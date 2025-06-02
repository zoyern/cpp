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


#define MSG_NON_DISPLAYABLE "Non displayable"
#define MSG_IMPOSSIBLE "impossible"
typedef double type_converter_t;

class ScalarConverter {
public:
	static void convert(const std::string& input);
private:
	~ScalarConverter();
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	ScalarConverter& operator=(const ScalarConverter&);

	enum ScalarType {
		SCALAR_UNDEFINED,
		SCALAR_CHAR,
		SCALAR_INT,
		SCALAR_FLOAT,
		SCALAR_DOUBLE
	};
	static ScalarType getScalarType(const std::string &input);
	static bool isInf(const std::string &input);
	static bool isFloatInf(const std::string &input);
	static bool isDoubleInf(const std::string &input);
	static bool isChar(const std::string &input);
	static bool isInt(const std::string &input);
	static bool isFloat(const std::string &input);
	static bool isDouble(const std::string &input);

	static char   toChar(const std::string& input);
	static int    toInt(const std::string& input);
	static float  toFloat(const std::string& input);
	static double toDouble(const std::string& input);

	static type_converter_t converter(const std::string &input);
};
