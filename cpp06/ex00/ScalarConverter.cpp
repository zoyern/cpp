/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:22:06 by marvin            #+#    #+#             */
/*   Updated: 2025/05/27 15:22:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }

bool checkDoublon(const std::string &input, char c){ return (input.find(c) == input.rfind(c));}
bool checkNagative(const std::string &input){ return ((input.find_last_of('-') == std::string::npos || input.find_last_of('-') == 0) && checkDoublon(input, '-'));}

bool ScalarConverter::isChar(const std::string &input)
{
	return ((input.length() == 1 && !std::isdigit(static_cast<unsigned char>(input[0]))) ||
			(input.length() == 3 && input[0] == '\'' && input[2] == '\''));
}

bool ScalarConverter::isInt(const std::string &input)
{
	return (input.find_first_not_of("-0123456789") == std::string::npos && checkNagative(input) && !isChar(input));
}

bool ScalarConverter::isFloat(const std::string &input)
{
	return (((input == "nanf" || input == "+inff" || input == "-inff") ||
			 (input.at(input.length() - 1) == 'f' &&
			  checkDoublon(input, '.') &&
			  input.find_first_not_of("-0123456789.f") == std::string::npos &&
			  checkNagative(input))));
}

bool ScalarConverter::isDouble(const std::string &input)
{
	return (((input == "nan" || input == "+inf" || input == "-inf") ||
			 (input.find('.') != std::string::npos &&
			  checkDoublon(input, '.') &&
			  input.find_first_not_of("-0123456789.") == std::string::npos &&
			  checkNagative(input))));
}

char ScalarConverter::toChar(const std::string &input)
{
	if (input.empty())
		throw std::runtime_error(MSG_IMPOSSIBLE);
	std::stringstream s(input);
	type_converter_t temps;
	if (!(s >> temps) || !s.eof() || s.bad() || s.fail()) 
		throw std::runtime_error(MSG_IMPOSSIBLE);
	if (temps < std::numeric_limits<char>::min() || temps > std::numeric_limits<char>::max())
		throw std::runtime_error(MSG_IMPOSSIBLE);
	if (!isprint(temps))
		throw std::runtime_error(MSG_NON_DISPLAYABLE);
	return static_cast<char>(temps);
}

int ScalarConverter::toInt(const std::string &input)
{
	if (input.empty())
		throw std::runtime_error(MSG_IMPOSSIBLE);
	std::stringstream s(input);
	type_converter_t temps;
	if (!(s >> temps) || !s.eof() || s.bad() || s.fail()) 
		throw std::runtime_error(MSG_IMPOSSIBLE);
	if (temps < std::numeric_limits<int>::min() || temps > std::numeric_limits<int>::max())
		throw std::runtime_error(MSG_IMPOSSIBLE);
	return static_cast<int>(temps);
}

float ScalarConverter::toFloat(const std::string &input)
{
	if (input.empty())
		throw std::runtime_error(MSG_IMPOSSIBLE);
	std::stringstream s(input);
	type_converter_t temps;
	if (!(s >> temps) || !s.eof() || s.bad() || s.fail()) 
		throw std::runtime_error(MSG_IMPOSSIBLE);
	    if (temps < -std::numeric_limits<float>::max() || temps > std::numeric_limits<float>::max())
        throw std::runtime_error(MSG_IMPOSSIBLE);
	return static_cast<float>(temps);
}

double ScalarConverter::toDouble(const std::string &input)
{
	if (input.empty())
		throw std::runtime_error(MSG_IMPOSSIBLE);
	std::stringstream s(input);
	type_converter_t temps;
	if (!(s >> temps) || !s.eof() || s.bad() || s.fail()) 
		throw std::runtime_error(MSG_IMPOSSIBLE);
	    if (temps < -std::numeric_limits<float>::max() || temps > std::numeric_limits<float>::max())
        throw std::runtime_error(MSG_IMPOSSIBLE);
	return static_cast<float>(temps);
}

/*type_converter_t ScalarConverter::converter(const std::string &input)
{
	if (input.empty())
		throw std::runtime_error(MSG_IMPOSSIBLE);
	std::stringstream s(input);
	
	type_converter_t temps;
	if (!(s >> temps) || !s.eof() || s.bad() || s.fail())
		throw std::runtime_error(MSG_IMPOSSIBLE);
	return temps;
}*/


void ScalarConverter::convert(const std::string &input)
{
	try
	{
		char c = toChar(input);
		std::cout << "char: '" << c << "'" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "char: " << e.what() << std::endl;
	}

	try
	{
		int i = toInt(input);
		std::cout << "int: " << i << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "int: " << e.what() << std::endl;
	}

	try
	{
		float f = toFloat(input);
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "float: " << e.what() << std::endl;
	}

	try
	{
		double d = toDouble(input);
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "double: " << e.what() << std::endl;
	}
}
