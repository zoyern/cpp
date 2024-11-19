/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:15:16 by almounib          #+#    #+#             */
/*   Updated: 2024/11/19 21:27:52 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contact {
	private:
		std::string _name;
		std::string _fname;
		std::string _lname;
		std::string _secret;
	public:
		Contact();
		~Contact();
};

