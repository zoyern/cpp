/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:21:55 by marvin            #+#    #+#             */
/*   Updated: 2025/05/27 15:21:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "BitcoinExchange.hpp"

template <typename Key, typename Value>
BitcoinExchange<Key,Value>::~BitcoinExchange() {}
template <typename Key, typename Value>
BitcoinExchange<Key,Value>::BitcoinExchange() : _database(), _key_check(0) {}
template <typename Key, typename Value>
BitcoinExchange<Key,Value>::BitcoinExchange(const BitcoinExchange &other) { *this = other; }
template <typename Key, typename Value>
BitcoinExchange<Key,Value>::BitcoinExchange(const std::string &path, char sep, bool (*key_check)(const Key &key)) { load(path, sep, key_check); }

template <typename Key, typename Value>
BitcoinExchange<Key,Value>	&BitcoinExchange<Key,Value>::operator=(const BitcoinExchange &other){
	if (this == &other) return (*this);
	return (
		_database = other._database,
		_key_check = other._key_check,
	*this);
}

template <typename Key, typename Value>
template <typename T>
bool	BitcoinExchange<Key,Value>::validate(const std::string &input, T &out, bool showErrors, const std::string &line,
		bool (*checker)(const T &)) const {
	std::istringstream ss(input);

	if (input.empty() || !(ss >> out) || ss.fail() ||
		(!ss.eof() && (ss >> std::ws, ss.peek() == 'f' && (ss.get(), ss >> std::ws)), 0) ||
		(ss >> std::ws, !ss.eof())) {
		return (showErrors && std::cerr << ERR_INPUT << line << std::endl, false); }

	if (!checker) return (true);
	try { return ((!checker(out)) ? false : true); }
	catch (const std::exception &e) { return (showErrors && std::cerr << e.what() << std::endl, false);}
}

template <typename Key, typename Value>
bool	BitcoinExchange<Key,Value>::parse(const std::string &line, char sep, Key &key, Value &value,
		bool showErrors, bool (*key_check)(const Key &), bool (*value_check)(const Value &)) const{
	if (line.empty()) return (false);
	
	size_t pos = line.find(sep);
	if (!validate((pos == std::string::npos) ? line : line.substr(0, pos), key, showErrors, line, key_check))
		return (false);
	if (pos == std::string::npos || !pos || pos >= line.length() - 1 || 
		line.find(sep, pos + 1) != std::string::npos) {
		return (showErrors && std::cerr << ERR_INPUT << line << std::endl, false); }

	return (validate(line.substr(pos + 1), value, showErrors, line, value_check));
}

template <typename Key, typename Value>
void	BitcoinExchange<Key,Value>::load(const std::string &path, char sep, bool (*key_check)(const Key &)) {

	std::ifstream file(path.c_str());
	if (!file.is_open()) (throw std::runtime_error(ERR_OPEN));
	std::map<Key, Value> temp;

	for (std::string line; std::getline(file, line);) {
		Key k; Value v;
		if (parse(line, sep, k, v, false, key_check)) temp[k] = v;
	}
	
	if (temp.empty()) throw (std::runtime_error(ERR_DATA));
	_key_check = key_check;
	_database.swap(temp);
}

template <typename Key, typename Value>
void	BitcoinExchange<Key,Value>::out(const std::string &path, char sep, void (*op)(const Value &, const Value &, const Key &),
			bool (*value_check)(const Value &)) {

	if (_database.empty()) (throw std::runtime_error(ERR_DATA));

	std::ifstream file(path.c_str());
	if (!file.is_open()) (throw std::runtime_error(ERR_OPEN));

	for (std::string line; std::getline(file, line);) {
		Key key; Value value;
		if (parse(line, sep, key, value, true, _key_check, value_check)) {
			typename std::map<Key, Value>::const_iterator it = _database.upper_bound(key);

			if (it != _database.begin()) { --it; op(it->second, value, key); }
			else { std::cerr << ERR_INPUT << key << std::endl; }
		}
	}
}

