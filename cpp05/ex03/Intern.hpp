/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:37:36 by marvin            #+#    #+#             */
/*   Updated: 2024/11/22 16:37:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

#ifndef INTERN
	#define INTERN "INTERN"
	#define INTERN_DEFAULT "Intern"
	#define INTERN_DESTROY "Fired !!"
	#define INTERN_CREATE "Recruited !"
	#define INTERN_COPY "Copying ..."
	#define INTERN_CONSTRUCT 1
	#define INTERN_SUCCES "creates :"
	#define INTERN_ERROR "Form name not recognized..."
	#define INTERN_FORMS {"shrubbery creation", "robotomy request", "presidential pardon"}
	#define INTERN_FSIZE 3
#endif

#include "AForm.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class	AForm;

class Intern
{
private:

	void	construct(std::string msg) const;

public:
	class FormNameError : public std::exception	{
	public:
		virtual const char *what() const throw();
	};
	~Intern();
	Intern();
	Intern(const Intern &cpy);

	Intern &operator=(const Intern &cpy);

	AForm*	ShrubberyCreation(const std::string& target) const;
	AForm*	RobotomyRequest(const std::string& target) const;
	AForm*	PresidentialPardon(const std::string& target) const;
	AForm* makeForm(const std::string& formName, const std::string& target);
};

