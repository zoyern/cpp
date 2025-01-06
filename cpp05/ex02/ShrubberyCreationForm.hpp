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
#include "Bureaucrat.hpp"
#include "AForm.hpp"

#ifndef SCFFORM
#define SCFFORM "shrubbery"
#define SCFFORM_SIGN 145
#define SCFFORM_EXEC 137
#endif

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
public:
	~ShrubberyCreationForm();
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string name);
	ShrubberyCreationForm(std::string name, int sign_grade, int exec_grade);
	ShrubberyCreationForm(int sign_grade, int exec_grade);
	ShrubberyCreationForm(const ShrubberyCreationForm &cpy);

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &cpy);

	void beSigned(const Bureaucrat &bureaucrat);
	const std::string &getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool getSigned() const;

	class GradeTooHighException	: public std::exception	{ public: virtual const char *what() const throw();};
	class GradeTooLowException	: public std::exception	{ public: virtual const char *what() const throw();};
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &form);
std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm *form);
