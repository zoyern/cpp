/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:17:10 by almounib          #+#    #+#             */
/*   Updated: 2024/11/21 22:51:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# ifndef LIST
#  define LIST_SIZE 8
# endif

# ifndef PROMPT
#  define PROMPT "PROMPT"
#  define PROMPT_ADD "ADD"
#  define PROMPT_SEARCH "SEARCH"
#  define PROMPT_EXIT "EXIT"
# endif

# ifndef CMD
#  define CMD_ADD "ADD"
#  define CMD_SEARCH "SEARCH"
#  define CMD_EXIT "EXIT"
# endif

# include "Contact.hpp"

class PhoneBook {
	private:
		int		_index;
		Contact	_folder[LIST_SIZE];
	public:
		PhoneBook();
		void	add();
		void	get();
		void	prompt();
		int		input();
};

#endif