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

#include "AForm.hpp"

AForm::~AForm() { std::cout << "AForm" << "\t\t : " << "name:[ " << _name << " ], " << " :  signed:[ " << _signed << " ], sign_grade:[ " << _sign_grade << " ], exec_grade:[ " << _exec_grade << " ]. destroyed !" << std::endl; }
AForm::AForm() : _name(AFORM), _signed(false), _sign_grade(GRADE_MIN), _exec_grade(GRADE_MIN) { std::cout << "AForm" << "\t\t : " << "name:[ " << _name << " ], " << " :  signed:[ " << _signed << " ], sign_grade:[ " << _sign_grade << " ], exec_grade:[ " << _exec_grade << " ]. created !" << std::endl; }
AForm::AForm(std::string name) : _name(name), _signed(false), _sign_grade(GRADE_MIN), _exec_grade(GRADE_MIN) { std::cout << "AForm" << "\t\t : " << "name:[ " << _name << " ], " << " :  signed:[ " << _signed << " ], sign_grade:[ " << _sign_grade << " ], exec_grade:[ " << _exec_grade << " ]. created !" << std::endl; }
AForm::AForm(std::string name, int sign_grade, int exec_grade) : _name(name), _signed(false), _sign_grade(sign_grade < GRADE_MAX ? throw(AForm::GradeTooHighException()) : (sign_grade > GRADE_MIN ? throw(AForm::GradeTooLowException()) : sign_grade)), _exec_grade(exec_grade < GRADE_MAX ? throw(AForm::GradeTooHighException()) : (exec_grade > GRADE_MIN ? throw(AForm::GradeTooLowException()) : exec_grade)) { std::cout << "AForm" << "\t\t : " << "name:[ " << _name << " ], " << " :  signed:[ " << _signed << " ], sign_grade:[ " << _sign_grade << " ], exec_grade:[ " << _exec_grade << " ]. created !" << std::endl; }
AForm::AForm(int sign_grade, int exec_grade) : _name(AFORM), _signed(false), _sign_grade(sign_grade < GRADE_MAX ? throw(AForm::GradeTooHighException()) : (sign_grade > GRADE_MIN ? throw(AForm::GradeTooLowException()) : sign_grade)), _exec_grade(exec_grade < GRADE_MAX ? throw(AForm::GradeTooHighException()) : (exec_grade > GRADE_MIN ? throw(AForm::GradeTooLowException()) : exec_grade)) { std::cout << "AForm" << "\t\t : " << "name:[ " << _name << " ], " << " :  signed:[ " << _signed << " ], sign_grade:[ " << _sign_grade << " ], exec_grade:[ " << _exec_grade << " ]. created !" << std::endl; }
AForm::AForm(const AForm &cpy) : _name(cpy._name), _sign_grade(cpy._sign_grade), _exec_grade(cpy._exec_grade)
{
	*this = cpy;
	std::cout << "AForm" << "\t\t : " << "name:[ " << _name << " ], " << "\t :  signed:[ " << _signed << " ], sign_grade:[ " << _sign_grade << " ], exec_grade:[ " << _exec_grade << " ]. cpy created !" << std::endl;
}

AForm &AForm::operator=(const AForm &cpy)
{
	if (this == &cpy)
		return (*this);
	_signed = cpy._signed;
	return (*this);
}

const std::string &AForm::getName() const { return (_name); }
int AForm::getSignGrade() const { return (_sign_grade); }
int AForm::getExecGrade() const { return (_exec_grade); }
bool AForm::getSigned() const { return (_signed); }

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	_signed = bureaucrat.getGrade() > _sign_grade ? throw(AForm::GradeTooLowException()) : true;
	std::cout << "AForm" << "\t\t\t : " << "name:[ " << bureaucrat.getName() << " ], " << " : signed AForm:[ " << _name << " ]." << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw() { return (GRADE_HIGHT); }
const char *AForm::GradeTooLowException::what() const throw() { return (GRADE_LOW); }

std::ostream &operator<<(std::ostream &out, const AForm &form) { return (out << "form name:[ " << form.getName() << " ], " << "\t :  signed:[ " << form.getSigned() << " ], sign_grade:[ " << form.getSignGrade() << " ], exec_grade:[ " << form.getExecGrade() << " ]." << std::endl); }
std::ostream &operator<<(std::ostream &out, const AForm *form) { return (!form ? out << form : out << *form); }
