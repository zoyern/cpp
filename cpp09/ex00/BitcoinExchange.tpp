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

#define PATH_DATA	"data/data.csv"
#define MIN_VALUE	0
#define MAX_VALUE	1000
#define SEP_DATA	','
#define SEP_INPUT	'|'

#define ERR_LOW		"Error: not a positive number."
#define ERR_LARGE	"Error: too large a number."
#define ERR_INPUT	"Error: bad input => "
#define ERR_OPEN	"Error: could not open file."
#define ERR_DATA	"Error: bad database."


template<typename Key, typename Value>
class BitcoinExchange
{
	private:
		std::map<Key, Value> _database;
		bool (*_key_check)(const Key &key);
		
	public:
		~BitcoinExchange() {};
		BitcoinExchange() : _database() {};
		BitcoinExchange(const BitcoinExchange &other) {*this = other};
		BitcoinExchange(const std::string &path, char sep, bool (*key_check)(const Key &key)) { load(path, sep, check); }

		BitcoinExchange &operator=(const BitcoinExchange &other) {
			if (this == &other) return (*this);
			return (_database = other._database, _key_check = other._key_check, *this);
		}

		void	load(const std::string &path, char sep, bool (*key_check)(const Key &key))
		{
			if (_database)
				_database.clear();
		}

		void    out(const std::string &path, char sep,
 void (*op)(const Value &value1, const Value &value2, const Key &key), bool (*value_check)(const Value &value))
		{

		}
};