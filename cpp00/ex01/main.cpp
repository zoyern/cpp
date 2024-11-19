/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:06:56 by almounib          #+#    #+#             */
/*   Updated: 2024/11/19 22:26:44 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _index(0){}
PhoneBook::~PhoneBook(){}

Contact::Contact(){}
Contact::~Contact(){}

void	print_prompt()
{
	std::cout << "\033[36;47;4m╔══❖═══════❖═══════❖═══════❖══╗\n";
	std::cout << "║  Welcome in PhoneBook       ║\n";
	std::cout << "║                             ║\n";
	std::cout << "║   Commands :                ║\n";
	std::cout << "║   -ADD      : Add contact   ║\n";
	std::cout << "║   -SEARCH   : Search contact║\n";
	std::cout << "║   -EXIT     : Exit program  ║\n";
	std::cout << "╚══❖═══════❖═══════❖═══════❖══╝\033[0m\n";
	std::cout << "                               \n";
	std::cout << "\033[36;47;3;1m❖ Input \033[0m\033[37m\033[0m";
}

int	get_inputs()
{
	std::string	input;
	std::cin >> input;
	std::cout << input;
	return (1);
}

int	main()
{
	PhoneBook	list();
	print_prompt();
	while (get_inputs())
		print_prompt();
	return (0);
}
