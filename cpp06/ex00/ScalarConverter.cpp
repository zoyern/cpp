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

bool ScalarConverter::isInfinity(const std::string &input) { return (!input.empty() && ((input == "nanf" || input == "+inff" || input == "-inff") || (input == "nan" || input == "+inf" || input == "-inf"))); }

char ScalarConverter::toChar(const std::string &input)
{
	type_converter_t temps = converter(input);
	if (isInfinity(input) || temps < std::numeric_limits<char>::min() || temps > std::numeric_limits<char>::max())
		throw std::runtime_error(MSG_OVERFLOW);
	if (temps < 32 || temps == 127)
		throw std::runtime_error(MSG_NON_DISPLAYABLE);
	return static_cast<char>(temps);
}

int ScalarConverter::toInt(const std::string &input)
{
	type_converter_t temps = converter(input);
	if (isInfinity(input) || (temps < std::numeric_limits<int>::min() || temps > std::numeric_limits<int>::max()))
		throw std::runtime_error(MSG_OVERFLOW);
	return static_cast<int>(temps);
}

float ScalarConverter::toFloat(const std::string &input)
{
	type_converter_t temps = converter(input);
	if (!isInfinity(input) && (temps < -std::numeric_limits<float>::max() || temps > std::numeric_limits<float>::max()))
		throw std::runtime_error(MSG_OVERFLOW);
	return static_cast<float>(temps);
}

double ScalarConverter::toDouble(const std::string &input)
{
	type_converter_t temps = converter(input);
	if (!isInfinity(input) && (temps < -std::numeric_limits<double>::max() || temps > std::numeric_limits<double>::max()))
		throw std::runtime_error(MSG_OVERFLOW);
	return static_cast<double>(temps);
}

type_converter_t ScalarConverter::converter(const std::string &input)
{
	if (input.empty())
		throw std::runtime_error(MSG_EMPTY);
	if (!isInfinity(input) && ((input.length() == 1 && !std::isdigit(input[0])) || (input.length() == 3 && input.find('\'') != input.rfind('\''))))
		return static_cast<type_converter_t>(input.length() == 1 ? input[0] : input[1]);
	if (input == "nan" || input == "nanf")
		return std::numeric_limits<type_converter_t>::quiet_NaN();
	if (input == "+inf" || input == "+inff")
		return std::numeric_limits<type_converter_t>::infinity();
	if (input == "-inf" || input == "-inff")
		return -std::numeric_limits<type_converter_t>::infinity();

	std::stringstream s(input);
	type_converter_t temps;
	if (!(s >> temps) || (!s.eof() && !(input.at(input.length() - 1) == 'f' && input.find('.') == input.rfind('.') && input.find('f') == input.rfind('f'))) || s.bad() || s.fail())
		throw std::runtime_error(MSG_IMPOSSIBLE);
	return (temps);
}

void ScalarConverter::convert(const std::string &input)
{
	try	{ char c = toChar(input); std::cout << "char: '" << c << "'" << std::endl;}
	catch (const std::exception &e)	{ std::cout << "char: " << e.what() << std::endl;}

	try	{ int i = toInt(input); std::cout << "int: " << i << std::endl;}
	catch (const std::exception &e) { std::cout << "int: " << e.what() << std::endl;}

	try	{ float f = toFloat(input); std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;}
	catch (const std::exception &e) { std::cout << "float: " << e.what() << std::endl;}

	try { double d = toDouble(input); std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;}
	catch (const std::exception &e) { std::cout << "double: " << e.what() << std::endl;}
}
