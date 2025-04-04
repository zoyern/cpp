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
void Intern::construct(std::string msg) const {	if (INTERN_CONSTRUCT) { std::cout << INTERN << "\t\t\t : " << msg << std::endl;}}

const char *Intern::FormNameError::what() const throw() { return (INTERN_ERROR);}

Intern			&Intern::operator=(const Intern &cpy){ if (this == &cpy) return (*this); return (*this);}

AForm*			Intern::ShrubberyCreation(const std::string& target) const { return (new ShrubberyCreationForm(target));}
AForm*			Intern::RobotomyRequest(const std::string& target) const { return (new RobotomyRequestForm(target));}
AForm*			Intern::PresidentialPardon(const std::string& target) const { return (new PresidentialPardonForm(target));}

AForm*			Intern::makeForm(const std::string& name, const std::string& target) { std::string forms[] = INTERN_FORMS;
	AForm* (Intern::*functions[INTERN_FSIZE])(const std::string&) const = {
        &Intern::ShrubberyCreation,
        &Intern::RobotomyRequest,
        &Intern::PresidentialPardon
    };
	for (int i = 0; i < INTERN_FSIZE; i++)
        if (forms[i] == name) return (construct("creates : form:[ " + name + " ], target:[ " + target + " ]"), (this->*functions[i])(target));
	throw (FormNameError());
}