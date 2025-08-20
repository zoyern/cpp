/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:21:55 by marvin            #+#    #+#             */
/*   Updated: 2025/05/27 15:21:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cctype>

#define MSG_NON_DISPLAYABLE "Non displayable"
#define MSG_IMPOSSIBLE "impossible"

typedef double type_converter_t;

class ScalarConverter
{
public:
	static void convert(const std::string &input);

private:
	~ScalarConverter();
	ScalarConverter();
	ScalarConverter(const ScalarConverter &);
	ScalarConverter &operator=(const ScalarConverter &);

	static bool isInfinity(const std::string &input);

	static char toChar(const std::string &input);
	static int toInt(const std::string &input);
	static float toFloat(const std::string &input);
	static double toDouble(const std::string &input);

	static type_converter_t converter(const std::string &input);
};
