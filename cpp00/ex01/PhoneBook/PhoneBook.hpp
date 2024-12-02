/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:17:10 by almounib          #+#    #+#             */
/*   Updated: 2024/12/02 14:08:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# ifndef LIST
#  define LIST_SIZE 8
# endif

# include "../Contact/Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

# ifndef CMD
#  define CMD_ADD "ADD"
#  define CMD_SEARCH "SEARCH"
#  define CMD_EXIT "EXIT"
# endif

class PhoneBook {
	private:
		int		_index;
		Contact	_folder[LIST_SIZE];
	public:
		~PhoneBook();
		PhoneBook();
		void	add();
		void	get();
		void	prompt();
		int		input();
};

#endif