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

#include <map>
#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

#define PATH_DATA "data/data.csv"
#define MIN_VALUE 0
#define MAX_VALUE 1000
#define SEP_DATA ','
#define SEP_INPUT '|'

#define NAME_KEY "date"
#define NAME_VALUE "value"

#define ERR_LOW "Error: not a positive number."
#define ERR_LARGE "Error: too large a number."
#define ERR_INPUT "Error: bad input => "
#define ERR_OPEN "Error: could not open file."
#define ERR_DATA "Error: bad database."

template <typename Key, typename Value>
class BitcoinExchange
{
private:
	std::map<Key, Value> _database;
	bool (*_key_check)(const Key &key);

	static bool parse(const std::string &line, char sep, Key &k, Value &v)
	{
		std::istringstream ss(line);
		std::string key_str, value_str;

		if (!std::getline(ss, key_str, sep) || !std::getline(ss, value_str) || std::getline(ss, value_str))
			return false;

		std::istringstream key_ss(key_str), value_ss(value_str);
		return (key_ss >> k) && key_ss.eof() && (value_ss >> v) && value_ss.eof();
	}

public:
	~BitcoinExchange() {};
	BitcoinExchange() : _database() {};
	BitcoinExchange(const BitcoinExchange &other) { *this = other; };
	BitcoinExchange(const std::string &path, char sep, bool (*key_check)(const Key &key)) { load(path, sep, key_check); }

	BitcoinExchange &operator=(const BitcoinExchange &other)
	{
		if (this == &other)
			return (*this);
		return (_database = other._database, _key_check = other._key_check, *this);
	}

	void load(const std::string &path, char sep, bool (*key_check)(const Key &))
	{
		std::ifstream file(path.c_str());
		if (!file.is_open())
			throw std::runtime_error(ERR_OPEN);
		_database.clear();
		_key_check = key_check;

		for (std::string line; std::getline(file, line);)
		{
			if (line.empty())
				continue;

			Key k;
			Value v;
			if (!parse(line, sep, k, v))
				continue;
			if (_key_check)
			{
				try { if (!_key_check(k)) continue;}
				catch (...) { continue; }
			}

			_database[k] = v;
		}
		if (_database.empty())
			throw std::runtime_error(ERR_DATA);
	}

	void out(const std::string &path, char sep,
			 void (*op)(const Value &, const Value &, const Key &),
			 bool (*value_check)(const Value &)) const
	{
		std::ifstream file(path.c_str());
		if (!file.is_open())
			throw std::runtime_error(ERR_OPEN);

		for (std::string line; std::getline(file, line);)
		{
			if (line.empty())
				continue;

			Key key;
			Value value;
			if (!parse(line, sep, key, value))
				{std::cerr << ERR_INPUT << line << std::endl; continue; }
			if (_key_check)
			{
				try {if (!_key_check(key)) continue; }
				catch (const std::exception &e) { std::cerr << e.what() << std::endl; continue; }
			}
			if (value_check)
			{
				try { value_check(value); }
				catch (const std::exception &e) { std::cerr << e.what() << std::endl; continue; }
			}



			typename std::map<Key, Value>::const_iterator it = _database.upper_bound(key);
			if (it == _database.begin())
			{
				std::cerr << ERR_INPUT << key << std::endl;
				continue;
			}
			--it;
			op(it->second, value, key);
		}
		
	}
};
