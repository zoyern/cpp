/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
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

    template<typename T>
    bool	validate(const std::string &input, T &out, bool showErrors, const std::string &line,
			bool (*checker)(const T &) = 0) const;
    bool	parse(const std::string &line, char sep, Key &key, Value &value,
        	bool showErrors, bool (*key_check)(const Key &) = 0, bool (*value_check)(const Value &) = 0) const;

public:
	~BitcoinExchange();
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange(const std::string &path, char sep, bool (*key_check)(const Key &key) = 0);

	BitcoinExchange &operator=(const BitcoinExchange &other);

	void	load(const std::string &path, char sep, bool (*key_check)(const Key &) = 0);
    void	out(const std::string &path, char sep, void (*op)(const Value &, const Value &, const Key &),
    		bool (*value_check)(const Value &) = 0);
};

#include "BitcoinExchange.tpp"