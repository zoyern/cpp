/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:17:10 by almounib          #+#    #+#             */
/*   Updated: 2024/11/21 23:42:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook() : _index(0) {
	for (size_t i = 0; i < LIST_SIZE; ++i)
		_folder[i].index = i + 1;
}

void	PhoneBook::add() {
	return (_folder[(_index) % LIST_SIZE] = Contact(_index),
		std::cout << "\033[2J\033[1;1H",
		_folder[(_index) % LIST_SIZE].show(true),
		(void)(++_index %= LIST_SIZE));
}

void	PhoneBook::get() { std::string fields[] = FIELDS; std::string input; int number; std::string index = "index";
	std::cout << "\033[36;47;4m╔══❖═══════❖══════════❖══════════❖════════❖══╗\n";
	std::cout << "║" << std::setw(10) << (index.length() > 10 ? index.substr(0, 9) + "." : index) << "|";
	for (size_t i = 0; i < FIELDS_SIZE && i < FIELD_SHOW; i++)
		std::cout << std::setw(10) << (fields[i].length() > 10 ? fields[i].substr(0, 9) + "." : fields[i]) << "|";
	std::cout << "║" <<  std::endl;
	for (size_t i = 0; i < LIST_SIZE; i++)
		_folder[i].show(false);
	std::cout << "╚══❖═══════❖══════════❖══════════❖════════❖══╝\033[0m\n\n";
	do {
		std::cout << "\033[36;47;3;1m❖ Entrez un nombre entre 1 et " << LIST_SIZE << "  \033[0m\033[37m\033[0m";
        std::getline(std::cin, input);
        number = std::atoi(input.c_str());
        if (number < 1 || number >= LIST_SIZE + 1 || input.empty())
            std::cout << "Le nombre est hors plage ou invalide !" << std::endl;
	} while (number < 1 || number >= LIST_SIZE + 1 || input.empty());
	std::cout << "\033[2J\033[1;1H";
	_folder[number - 1].show(true);
}

void	PhoneBook::prompt() {
	std::cout << "\033[36;47;4m╔══❖═══════❖═══════❖═══════❖═══════❖═══════❖═══════❖═══════❖══╗\033[0m\n";
	std::cout << "\033[36;47;4m║                     Welcome in PhoneBook                    ║\033[0m\n";
	std::cout << "\033[36;47;4m║                                                             ║\033[0m\n";
	std::cout << "\033[36;47;4m║   Commands :                                                ║\033[0m\n";
	std::cout << "\033[36;47;4m║      -ADD      : Add contact                                ║\033[0m\n";
	std::cout << "\033[36;47;4m║      -SEARCH   : Search contact                             ║\033[0m\n";
	std::cout << "\033[36;47;4m║      -EXIT     : Exit program                               ║\033[0m\n";
	std::cout << "\033[36;47;4m╚══❖═══════❖═══════❖═══════❖═══════❖═══════❖═══════❖═══════❖══╝\033[0m\n";
	std::cout << "                               \n";
	std::cout << "\033[36;47;3;1m❖ Input \033[0m\033[37m\033[0m";
}

int		PhoneBook::input()
{
	std::string	input;
	while (1)
	{
		prompt();
		std::getline(std::cin, input);
		std::cout << "\033[2J\033[1;1H";
		if (CMD_ADD == input)
			add();
		if (CMD_SEARCH == input)
			get();
		if (CMD_EXIT == input)
			return (0);
	}
	return (0);
}