/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:22:06 by marvin            #+#    #+#             */
/*   Updated: 2025/05/27 15:22:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &) {}

BitcoinExchange    &BitcoinExchange::operator=(const BitcoinExchange &) { return (*this);
}

bool    BitcoinExchange::checkDate(const std::string &input)
{
    int y, m, d;
    std::istringstream iss(input);

    if (input.size() != 10 || !(iss >> y) || iss.get() != '-' || !(iss >> m) || iss.get() != '-' || !(iss >> d))
        return (false);
    std::tm tm{};
    tm.tm_year = y-1900;
    tm.tm_mon = m - 1;
    tm.tm_mday = d;
    tm.tm_isdst = -1;
    time_t t = mktime(&tm);
    return (t != (time_t)-1 
        && tm.tm_year == y - 1900
        && tm.tm_mon == m - 1
        && tm.tm_mday == d
        && t <= std::time(0));
}

void BitcoinExchange::parse(const std::string &input)
{
    std::ifstream src(input.c_str());
    std::stringstream s(input);
    float value;
    std::string date;
    std::map<std::string, float> m;
    
    while (std::getline(s, date,','))
    {
        cout<<num<<" ";.
    }
    for ( line; std::getline(src, line); ) 
		if (!())
    if (value < MIN_VALUE)
        throw (std::runtime_error(ERR_NEGATIVE));
    if (value > MAX_VALUE)
        throw (std::runtime_error(ERR_LARGE));
    if (checkDate(date))
        throw (std::runtime_error(ERR_INPUT));
}


