/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:15:16 by almounib          #+#    #+#             */
/*   Updated: 2024/11/22 16:13:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

# ifndef FIELDS
#  define FIELDS {"first name", "last name", "nickname", "phone number", "darkest secret"}
#  define FIELDS_SIZE 5
#  define FIELD_SHOW 3
# endif

class Contact {
	private:
		std::string _fields[FIELDS_SIZE];
	public:
		~Contact();
		Contact();
		Contact(int id);
		int		index;
		void	show(bool endline);
};

#endif
