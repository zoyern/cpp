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

#include "ScalarConverter.hpp"

void	test_converter(std::string str) {
	std::cout << "--- Input: " << str << " ---" << std::endl;
	ScalarConverter::convert(str);
	std::cout << std::endl;
}

int main(void) {
	// Tests simples classiques
    test_converter("0");
    test_converter("42");
    test_converter("-42");
    test_converter("a");
    test_converter("z");
    test_converter("A");
    test_converter("'r'");
    test_converter("'B'");
    test_converter("' '");
	test_converter("'\\n'");

    // Float/double classiques
    test_converter("42.0");
    test_converter("42.0f");
    test_converter("-42.2");
    test_converter("42.2f");

    // Notations spéciales
    test_converter("nan");
    test_converter("nanf");
    test_converter("+inf");
    test_converter("-inf");
    test_converter("+inff");
    test_converter("-inff");

    // Valeurs limites int
    test_converter("2147483647");      // INT_MAX
    test_converter("-2147483648");     // INT_MIN
    test_converter("2147483648");      // INT_MAX + 1 overflow
    test_converter("-2147483649");     // INT_MIN - 1 overflow

    // Valeurs limites float/double
    test_converter("3.4028235e+38f");  // float max
    test_converter("-3.4028235e+38f"); // float min
    test_converter("1.7976931348623157e+308");  // double max
    test_converter("-1.7976931348623157e+308"); // double min
    test_converter("3.5e+38f");        // > float max, overflow
    test_converter("1.8e+308");        // > double max, overflow

    // Cas invalides / erreurs parsing
    test_converter("");
    test_converter("42..0");
    test_converter("4.2.2");
    test_converter("--42");
    test_converter("++42");
    test_converter("42.2ff");
    test_converter("f42");
    test_converter("42 42");
    test_converter("42\t42");
    test_converter("-f");
    test_converter("+");
    test_converter("-");
    test_converter("f");
    test_converter(".");

    // Chars non numériques isolés
    test_converter(" ");
    test_converter("\n");
    test_converter("\t");
    test_converter("\0");
    test_converter("é");

    // Longues chaînes
    test_converter(std::string(1000, '9'));
    test_converter(std::string(10000, 'a'));

    // Caractères spéciaux en début/fin
    test_converter("42f ");
    test_converter(" 42f");
    test_converter(" 42f ");

    // Cas limites char non affichable
    test_converter("31");    // non affichable
    test_converter("127");   // DEL char
    test_converter("128");   // hors char

    // Quelques cas sympas
    test_converter("0.0f");
    test_converter("-0.0f");
    test_converter("+0.0");
    test_converter("+0.0f");
    test_converter("0.");
    test_converter(".0");
    test_converter("1e10");
    test_converter("-1e10");
    test_converter("1e-10");
    test_converter("-1e-10");
	return 0;
}