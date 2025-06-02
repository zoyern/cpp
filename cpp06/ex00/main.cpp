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

/*

double ScalarConverter::parseInput(const std::string &input)
{
	if (input.empty())
		throw std::runtime_error(MSG_IMPOSSIBLE);

	// Cas unique d’un caractère non chiffre (ex: 'a')
	if (input.length() == 1 && !std::isdigit(input[0]))
		return static_cast<double>(input[0]);

	// Cas spéciaux valides
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return static_cast<double>(std::strtof(input.c_str(), NULL));
	if (input == "-inf" || input == "+inf" || input == "nan")
		return std::strtod(input.c_str(), NULL);

	bool has_f_suffix = false;
	std::string to_parse = input;

	// Gère les suffixes 'f' pour float
	if (input.length() > 1 && input.back() == 'f')
	{
		has_f_suffix = true;
		to_parse = input.substr(0, input.length() - 1);
	}

	char *end = NULL;
	errno = 0; // pour détecter l'overflow
	double val = std::strtod(to_parse.c_str(), &end);

	// Erreur de conversion
	if (*end != '\0' || errno == ERANGE)
		throw std::runtime_error(MSG_IMPOSSIBLE);

	// Si on demande un float mais que la valeur dépasse ce qu’un float peut contenir
	if (has_f_suffix)
	{
		if (std::isnan(val) || std::isinf(val))
			return val; // nanf ou inff sont déjà gérés
		if (val < -std::numeric_limits<float>::max() || val > std::numeric_limits<float>::max())
			throw std::runtime_error(MSG_IMPOSSIBLE);
	}
	else
	{
		// S’il y a un 'f' ailleurs dans l’input mais pas en suffixe
		if (input.find('f') != std::string::npos)
			throw std::runtime_error(MSG_IMPOSSIBLE);
		// Si le double dépasse ses limites, on vérifie que ce soit un overflow
		if (!std::isnan(val) && !std::isinf(val) &&
			(val < -std::numeric_limits<double>::max() || val > std::numeric_limits<double>::max()))
			throw std::runtime_error(MSG_IMPOSSIBLE);
	}

	return val;
}

*/

#include "ScalarConverter.hpp"

void	test_converter(std::string str) {
	std::cout << "--- Input: " << str << " ---" << std::endl;
	ScalarConverter::convert(str);
	std::cout << std::endl;
}

int main(void) {
	test_converter("0");
	test_converter("42");
	test_converter("42.0");
	test_converter("42.0f");
	test_converter("42.2");
	test_converter("-42.2");
	test_converter("42.2f");
	test_converter("-inff");
	test_converter("+inf");
	test_converter("nan");
	test_converter("invalid");
	test_converter("42.2ff");
	test_converter("4.2.2f");
	test_converter("--42");
	test_converter("2147483647");
	test_converter("2147483648");
	test_converter("");
	test_converter("999999999999999999f");
	test_converter("999999999999999999999999999999999999999999.9");
	test_converter("-1");

	return 0;
}