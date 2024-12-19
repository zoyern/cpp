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

# include <iostream>

int main()
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "adresse de la string en mémoire\t: " << &string << std::endl;
	std::cout << "adresse stockée dans stringPTR\t: " <<  stringPTR << std::endl;
	std::cout << "adresse stockée dans stringREF\t: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "valeur de la string\t\t: " << string << std::endl;
	std::cout << "valeur pointée par stringPTR\t: " << *stringPTR << std::endl;
	std::cout << "valeur pointée par stringREF\t: " << stringREF << std::endl;
	return (0);
}
