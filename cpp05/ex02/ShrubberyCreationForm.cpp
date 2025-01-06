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

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm() { std::cout << "ShrubberyCreationForm" << "\t\t : " << "name:[ " << _name << " ], " << " :  signed:[ " << _signed << " ], sign_grade:[ " << _sign_grade << " ], exec_grade:[ " << _exec_grade << " ]. destroyed !" << std::endl; }
ShrubberyCreationForm::ShrubberyCreationForm() : _name(FORM), _signed(false), _sign_grade(GRADE_MIN), _exec_grade(GRADE_MIN) { std::cout << "ShrubberyCreationForm" << "\t\t : " << "name:[ " << _name << " ], " << " :  signed:[ " << _signed << " ], sign_grade:[ " << _sign_grade << " ], exec_grade:[ " << _exec_grade << " ]. created !" << std::endl; }
ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : _name(name), _signed(false), _sign_grade(GRADE_MIN), _exec_grade(GRADE_MIN) { std::cout << "ShrubberyCreationForm" << "\t\t : " << "name:[ " << _name << " ], " << " :  signed:[ " << _signed << " ], sign_grade:[ " << _sign_grade << " ], exec_grade:[ " << _exec_grade << " ]. created !" << std::endl; }
ShrubberyCreationForm::ShrubberyCreationForm(std::string name, int sign_grade, int exec_grade) : _name(name), _signed(false), _sign_grade(sign_grade < GRADE_MAX ? throw(ShrubberyCreationForm::GradeTooHighException()) : (sign_grade > GRADE_MIN ? throw(ShrubberyCreationForm::GradeTooLowException()) : sign_grade)), _exec_grade(exec_grade < GRADE_MAX ? throw(ShrubberyCreationForm::GradeTooHighException()) : (exec_grade > GRADE_MIN ? throw(ShrubberyCreationForm::GradeTooLowException()) : exec_grade)) { std::cout << "ShrubberyCreationForm" << "\t\t : " << "name:[ " << _name << " ], " << " :  signed:[ " << _signed << " ], sign_grade:[ " << _sign_grade << " ], exec_grade:[ " << _exec_grade << " ]. created !" << std::endl; }
ShrubberyCreationForm::ShrubberyCreationForm(int sign_grade, int exec_grade) : _name(FORM), _signed(false), _sign_grade(sign_grade < GRADE_MAX ? throw(ShrubberyCreationForm::GradeTooHighException()) : (sign_grade > GRADE_MIN ? throw(ShrubberyCreationForm::GradeTooLowException()) : sign_grade)), _exec_grade(exec_grade < GRADE_MAX ? throw(ShrubberyCreationForm::GradeTooHighException()) : (exec_grade > GRADE_MIN ? throw(ShrubberyCreationForm::GradeTooLowException()) : exec_grade)) { std::cout << "ShrubberyCreationForm" << "\t\t : " << "name:[ " << _name << " ], " << " :  signed:[ " << _signed << " ], sign_grade:[ " << _sign_grade << " ], exec_grade:[ " << _exec_grade << " ]. created !" << std::endl; }
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : _name(cpy._name), _sign_grade(cpy._sign_grade), _exec_grade(cpy._exec_grade)
{
	*this = cpy;
	std::cout << "ShrubberyCreationForm" << "\t\t : " << "name:[ " << _name << " ], " << "\t :  signed:[ " << _signed << " ], sign_grade:[ " << _sign_grade << " ], exec_grade:[ " << _exec_grade << " ]. cpy created !" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpy)
{
	if (this == &cpy)
		return (*this);
	_signed = cpy._signed;
	return (*this);
}

const std::string &ShrubberyCreationForm::getName() const { return (_name); }
int ShrubberyCreationForm::getSignGrade() const { return (_sign_grade); }
int ShrubberyCreationForm::getExecGrade() const { return (_exec_grade); }
bool ShrubberyCreationForm::getSigned() const { return (_signed); }

void ShrubberyCreationForm::beSigned(const Bureaucrat &bureaucrat)
{
	_signed = bureaucrat.getGrade() > _sign_grade ? throw(ShrubberyCreationForm::GradeTooLowException()) : true;
	std::cout << "ShrubberyCreationForm" << "\t\t\t : " << "name:[ " << bureaucrat.getName() << " ], " << " : signed ShrubberyCreationForm:[ " << _name << " ]." << std::endl;
}

const char *ShrubberyCreationForm::GradeTooHighException::what() const throw() { return (GRADE_HIGHT); }
const char *ShrubberyCreationForm::GradeTooLowException::what() const throw() { return (GRADE_LOW); }

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &form) { return (out << "form name:[ " << form.getName() << " ], " << "\t :  signed:[ " << form.getSigned() << " ], sign_grade:[ " << form.getSignGrade() << " ], exec_grade:[ " << form.getExecGrade() << " ]." << std::endl); }
std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm *form) { return (!form ? out << form : out << *form); }
