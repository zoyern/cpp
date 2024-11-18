/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:15:16 by almounib          #+#    #+#             */
/*   Updated: 2024/11/18 23:56:04 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contact {
	private:
		std::string name;
		std::string fname;
		std::string lname;
		std::string secret;
	public:
		Contact();
		~Contact();
};

Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}
