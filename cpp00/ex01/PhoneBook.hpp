/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:17:10 by almounib          #+#    #+#             */
/*   Updated: 2024/11/22 00:29:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# ifndef LIST
#  define LIST_SIZE 8
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