/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:06:56 by almounib          #+#    #+#             */
/*   Updated: 2024/11/21 22:13:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact() { std::string fields[] = FIELDS; for (size_t i = 0; i < FIELDS_SIZE; ++i) _fields[i] = "empty", index = -1; }
Contact::Contact(int id) { std::string fields[] = FIELDS;
    for (size_t i = 0; i < FIELDS_SIZE; ++i)
		std::cout << "\033[36;47;3;1m❖ " << fields[i] << "  \033[0m\033[37m\033[0m" << std::endl, std::getline(std::cin, _fields[i]);
	index = id;
	std::cout << "\033[2J\033[1;1H";
}
Contact::~Contact(){}
void
Contact::show(bool endline){ std::string fields[] = FIELDS; std::string strindex = "index";
	
	if (endline)
	{
    	std::cout << "\033[36;47;4m╔══❖═══════❖══════════❖══════════❖════════❖══╗\n";
   		std::cout << "║ " << std::setw(3) << std::right << 0 <<": " << std::setw(10) << std::left 
              << (strindex.length() > 10 ? strindex.substr(0, 9) + "." : strindex) 
              << " ║ " << std::setw(24) << std::right << index << " ║" << std::endl;
		for (size_t i = 0; i < FIELDS_SIZE; i++) {
			std::string fieldDisplay = (fields[i].length() > 10) ? fields[i].substr(0, 9) + "." : fields[i];
			std::string fieldValue = _fields[i].empty() ? "empty" : _fields[i];
			std::cout << "║ " << std::setw(3) << std::right << i + 1 <<": " << std::setw(10) << std::left 
				<< (fields[i].length() > 10 ? fields[i].substr(0, 9) + "." : fields[i]) 
				<< " ║ " << std::setw(24) << std::right << _fields[i] << " ║" << std::endl;
		}
		std::cout << "╚══❖═══════❖══════════❖══════════❖════════❖══╝\033[0m\n\n";
		return ;
	}
	std::cout << "║" << std::setw(10) << index << "|";
	for (size_t i = 0; i < FIELD_SHOW; i++)
		std::cout << std::setw(10) << (_fields[i].length() > 10 ? _fields[i].substr(0, 9) + "." : _fields[i]) << "|" << (endline ? "\n" : "");
	std::cout << "║" << std::endl;
}


PhoneBook::PhoneBook() : _index(0){ for (size_t i = 0; i < LIST_SIZE; ++i) _folder[i].index = i;}
PhoneBook::~PhoneBook(){ std::cout << "destruction of PhoneBook" << std::endl; }
void
PhoneBook::add() { return (_folder[(_index) % LIST_SIZE] = Contact(_index), _folder[(_index) % LIST_SIZE].show(true), (void)(++_index %= LIST_SIZE)); }
void
PhoneBook::get() { std::string fields[] = FIELDS; std::string input; int number; std::string index = "index";
	std::cout << "\033[36;47;4m╔══❖═══════❖══════════❖══════════❖════════❖══╗\n";
	std::cout << "║" << std::setw(10) << (index.length() > 10 ? index.substr(0, 9) + "." : index) << "|";
	for (size_t i = 0; i < FIELDS_SIZE && i < FIELD_SHOW; i++)
		std::cout << std::setw(10) << (fields[i].length() > 10 ? fields[i].substr(0, 9) + "." : fields[i]) << "|";
	std::cout << "║" <<  std::endl;
	for (size_t i = 0; i < LIST_SIZE; i++)
		_folder[i].show(false);
	std::cout << "╚══❖═══════❖══════════❖══════════❖════════❖══╝\033[0m\n\n";
	do {
		std::cout << "\033[36;47;3;1m❖ Entrez un nombre entre 0 et " << LIST_SIZE - 1 << "  \033[0m\033[37m\033[0m";
        std::getline(std::cin, input);
        number = atoi(input.c_str());
        if (number < 0 && number >= LIST_SIZE)
            std::cout << "Le nombre est hors plage ou invalide !" << std::endl;
	} while (number < 0 && number >= LIST_SIZE);
	std::cout << "\033[2J\033[1;1H";
	_folder[number].show(true);
	
}
void
PhoneBook::prompt()
{
	std::cout << "\033[36;47;4m╔══❖═══════❖═══════❖═══════❖═══════❖═══════❖═══════❖═══════❖══╗\n";
	std::cout << "║                     Welcome in PhoneBook                    ║\n";
	std::cout << "║                                                             ║\n";
	std::cout << "║   Commands :                                                ║\n";
	std::cout << "║      -ADD      : Add contact                                ║\n";
	std::cout << "║      -SEARCH   : Search contact                             ║\n";
	std::cout << "║      -EXIT     : Exit program                               ║\n";
	std::cout << "╚══❖═══════❖═══════❖═══════❖═══════❖═══════❖═══════❖═══════❖══╝\033[0m\n";
	std::cout << "                               \n";
	std::cout << "\033[36;47;3;1m❖ Input \033[0m\033[37m\033[0m";
}

int			PhoneBook::input()
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

int	main()
{
	PhoneBook	list;
	return (list.input());
}
