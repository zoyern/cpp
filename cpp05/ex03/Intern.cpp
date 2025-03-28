/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:37:34 by marvin            #+#    #+#             */
/*   Updated: 2024/11/22 16:37:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::~Intern() { construct(INTERN_DESTROY);}
Intern::Intern(const Intern &cpy) {*this = cpy; construct(INTERN_COPY);}
Intern::Intern()  { construct(INTERN_CREATE);}
void Intern::construct(std::string msg) const {	if (INTERN_CONSTRUCT) { std::cout << INTERN << "\t\t : " << msg << std::endl;}}

const char *Intern::FormNameError::what() const throw() { return (INTERN_ERROR);}

Intern			&Intern::operator=(const Intern &cpy){ if (this == &cpy) return (*this); return (*this);}

AForm*			Intern::makeForm(const std::string& name, const std::string& target) { 	std::string forms[] = INTERN_FORMS;
	if (name == forms[0])
		return (construct(INTERN_SUCCES + forms[0]), new ShrubberyCreationForm(target));
	if (name == forms[1])
		return (construct(INTERN_SUCCES + forms[1]), new RobotomyRequestForm(target));
	if (name == forms[2])
		return (construct(INTERN_SUCCES + forms[2]), new PresidentialPardonForm(target));
	throw (FormNameError());
}