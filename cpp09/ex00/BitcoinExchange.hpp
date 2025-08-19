/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:21:55 by marvin            #+#    #+#             */
/*   Updated: 2025/05/27 15:21:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ctime>
#include <sstream>
#include <fstream>
#include <map>

#define PATH_DB "data/data.csv"
#define MIN_VALUE 0
#define MAX_VALUE 1000
#define SEP_DATA ','
#define SEP_INPUT '|'
#define ERR_NEGATIVE "not a positive number"
#define ERR_LARGE "too large a number."
#define ERR_INPUT "bad input => "
#define ERR_EMPTY "empty !"

class BitcoinExchange
{
public:
	static void parse(const std::string &path);
private:
	~BitcoinExchange();
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &);
	BitcoinExchange &operator=(const BitcoinExchange &);

    static bool    checkDate(const std::string &input);
};
