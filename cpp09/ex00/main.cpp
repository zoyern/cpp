
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:36:29 by marvin            #+#    #+#             */
/*   Updated: 2024/11/22 16:36:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.tpp"

bool    is_date(const std::string &key)
{
    int y, m, d;
    std::istringstream iss(key);
    if (key.size() != 10 || !(iss >> y) || iss.get() != '-' || !(iss >> m)
		|| iss.get() != '-' || !(iss >> d) || !iss.eof())
        return (false);
    std::tm tm = std::tm();
    tm.tm_year = y-1900; tm.tm_mon = m-1; tm.tm_mday = d; tm.tm_isdst = -1;
    time_t t = mktime(&tm);
	if (!(t != (time_t)-1 
        && tm.tm_year == y - 1900 && tm.tm_mon == m - 1 && tm.tm_mday == d
        && t <= std::time(0)))
		throw (std::runtime_error(ERR_INPUT + key));
    return (true);
}

bool	is_value(const double &value) { 
	if (value < MIN_VALUE) { throw std::runtime_error(ERR_LOW); }
	if (value > MAX_VALUE) { throw std::runtime_error(ERR_LARGE); }
	return (true);
}

void operation(const double &value1, const double &value2, const std::string &key)
{
	std::cout << key << " => " << value1 << " * " << value2 << " = " << value1 * value2 << std::endl;
}


int main(int ac, char **av){
    if (ac != 2) { return (std::cerr << ERR_OPEN << std::endl, 1); }

    try { BitcoinExchange<std::string,double> (PATH_DATA, SEP_DATA, &is_date, &is_value).out(av[1], SEP_INPUT, &operation);}
    catch (const std::exception& e) { return (std::cerr << e.what() << std::endl, 1); }
    
    return (0);
}
