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

#define MIN_VALUE 0
#define MAX_VALUE 1000
#define PATH_DB "data/data.csv"

class BitcoinExchange
{
public:
    ~BitcoinExchange();
    BitcoinExchange();
    BitcoinExchange(const std::string &file);
    BitcoinExchange(const BitcoinExchange &cpy);
    BitcoinExchange &operator=(const BitcoinExchange &cpy);

    bool    checkDate(const std::string &input);
};
