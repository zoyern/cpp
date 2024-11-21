/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:15:16 by almounib          #+#    #+#             */
/*   Updated: 2024/11/22 00:27:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>

Contact::Contact()
{
	std::string fields[] = FIELDS;

	for (size_t i = 0; i < FIELDS_SIZE; ++i)
		_fields[i] = "empty", index = -1;
}

Contact::Contact(int id)
{
	std::string fields[] = FIELDS;

    for (size_t i = 0; i < FIELDS_SIZE; ++i)
	{
        do {
			std::cout << "\033[36;47;3;1m❖ " << fields[i] << "  \033[0m\033[37m\033[0m" << std::endl;
            std::getline(std::cin, _fields[i]);
        }
		while (_fields[i].empty());
	}
	index = id;
}

void	Contact::show(bool endline){
	std::string fields[] = FIELDS;
	std::string strindex = "index";

	if (endline)
	{
    	std::cout << "\n\033[36;47;4m╔══❖═══════❖══════════❖══════════❖════════❖══╗\n";
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
