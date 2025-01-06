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

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm() { std::cout << "RobotomyRequestForm" << "\t\t : " << "name:[ " << _name << " ], " << " :  signed:[ " << _signed << " ], sign_grade:[ " << _sign_grade << " ], exec_grade:[ " << _exec_grade << " ]. destroyed !" << std::endl; }
RobotomyRequestForm::RobotomyRequestForm() : _name(FORM), _signed(false), _sign_grade(GRADE_MIN), _exec_grade(GRADE_MIN) { std::cout << "RobotomyRequestForm" << "\t\t : " << "name:[ " << _name << " ], " << " :  signed:[ " << _signed << " ], sign_grade:[ " << _sign_grade << " ], exec_grade:[ " << _exec_grade << " ]. created !" << std::endl; }
RobotomyRequestForm::RobotomyRequestForm(std::string name) : _name(name), _signed(false), _sign_grade(GRADE_MIN), _exec_grade(GRADE_MIN) { std::cout << "RobotomyRequestForm" << "\t\t : " << "name:[ " << _name << " ], " << " :  signed:[ " << _signed << " ], sign_grade:[ " << _sign_grade << " ], exec_grade:[ " << _exec_grade << " ]. created !" << std::endl; }
RobotomyRequestForm::RobotomyRequestForm(std::string name, int sign_grade, int exec_grade) : _name(name), _signed(false), _sign_grade(sign_grade < GRADE_MAX ? throw(RobotomyRequestForm::GradeTooHighException()) : (sign_grade > GRADE_MIN ? throw(RobotomyRequestForm::GradeTooLowException()) : sign_grade)), _exec_grade(exec_grade < GRADE_MAX ? throw(RobotomyRequestForm::GradeTooHighException()) : (exec_grade > GRADE_MIN ? throw(RobotomyRequestForm::GradeTooLowException()) : exec_grade)) { std::cout << "RobotomyRequestForm" << "\t\t : " << "name:[ " << _name << " ], " << " :  signed:[ " << _signed << " ], sign_grade:[ " << _sign_grade << " ], exec_grade:[ " << _exec_grade << " ]. created !" << std::endl; }
RobotomyRequestForm::RobotomyRequestForm(int sign_grade, int exec_grade) : _name(FORM), _signed(false), _sign_grade(sign_grade < GRADE_MAX ? throw(RobotomyRequestForm::GradeTooHighException()) : (sign_grade > GRADE_MIN ? throw(RobotomyRequestForm::GradeTooLowException()) : sign_grade)), _exec_grade(exec_grade < GRADE_MAX ? throw(RobotomyRequestForm::GradeTooHighException()) : (exec_grade > GRADE_MIN ? throw(RobotomyRequestForm::GradeTooLowException()) : exec_grade)) { std::cout << "RobotomyRequestForm" << "\t\t : " << "name:[ " << _name << " ], " << " :  signed:[ " << _signed << " ], sign_grade:[ " << _sign_grade << " ], exec_grade:[ " << _exec_grade << " ]. created !" << std::endl; }
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : _name(cpy._name), _sign_grade(cpy._sign_grade), _exec_grade(cpy._exec_grade)
{
	*this = cpy;
	std::cout << "RobotomyRequestForm" << "\t\t : " << "name:[ " << _name << " ], " << "\t :  signed:[ " << _signed << " ], sign_grade:[ " << _sign_grade << " ], exec_grade:[ " << _exec_grade << " ]. cpy created !" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &cpy)
{
	if (this == &cpy)
		return (*this);
	return (*this);
}

const std::string &RobotomyRequestForm::getName() const { return (_name); }
int RobotomyRequestForm::getSignGrade() const { return (_sign_grade); }
int RobotomyRequestForm::getExecGrade() const { return (_exec_grade); }
bool RobotomyRequestForm::getSigned() const { return (_signed); }

void RobotomyRequestForm::beSigned(const Bureaucrat &bureaucrat)
{
	_signed = bureaucrat.getGrade() > _sign_grade ? throw(RobotomyRequestForm::GradeTooLowException()) : true;
	std::cout << "RobotomyRequestForm" << "\t\t\t : " << "name:[ " << bureaucrat.getName() << " ], " << " : signed RobotomyRequestForm:[ " << _name << " ]." << std::endl;
}

const char *RobotomyRequestForm::GradeTooHighException::what() const throw() { return (GRADE_HIGHT); }
const char *RobotomyRequestForm::GradeTooLowException::what() const throw() { return (GRADE_LOW); }

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &form) { return (out << "form name:[ " << form.getName() << " ], " << "\t :  signed:[ " << form.getSigned() << " ], sign_grade:[ " << form.getSignGrade() << " ], exec_grade:[ " << form.getExecGrade() << " ]." << std::endl); }
std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm *form) { return (!form ? out << form : out << *form); }
