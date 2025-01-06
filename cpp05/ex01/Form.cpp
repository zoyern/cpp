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

#include "Form.hpp"

Form::~Form() { std::cout << "Form" << "\t\t : " << "name:[ " << _name << " ], " << " :  signed:[ " << _signed << " ], sign_grade:[ " << _sign_grade << " ], exec_grade:[ " << _exec_grade << " ]. destroyed !" << std::endl; }
Form::Form() : _name(FORM), _signed(false), _sign_grade(GRADE_MIN), _exec_grade(GRADE_MIN) { std::cout << "Form" << "\t\t : " << "name:[ " << _name << " ], " << " :  signed:[ " << _signed << " ], sign_grade:[ " << _sign_grade << " ], exec_grade:[ " << _exec_grade << " ]. created !" << std::endl; }
Form::Form(std::string name) : _name(name), _signed(false), _sign_grade(GRADE_MIN), _exec_grade(GRADE_MIN) { std::cout << "Form" << "\t\t : " << "name:[ " << _name << " ], " << " :  signed:[ " << _signed << " ], sign_grade:[ " << _sign_grade << " ], exec_grade:[ " << _exec_grade << " ]. created !" << std::endl; }
Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name), _signed(false), _sign_grade(sign_grade < GRADE_MAX ? throw(Form::GradeTooHighException()) : (sign_grade > GRADE_MIN ? throw(Form::GradeTooLowException()) : sign_grade)), _exec_grade(exec_grade < GRADE_MAX ? throw(Form::GradeTooHighException()) : (exec_grade > GRADE_MIN ? throw(Form::GradeTooLowException()) : exec_grade)) { std::cout << "Form" << "\t\t : " << "name:[ " << _name << " ], " << " :  signed:[ " << _signed << " ], sign_grade:[ " << _sign_grade << " ], exec_grade:[ " << _exec_grade << " ]. created !" << std::endl; }
Form::Form(int sign_grade, int exec_grade) : _name(FORM), _signed(false), _sign_grade(sign_grade < GRADE_MAX ? throw(Form::GradeTooHighException()) : (sign_grade > GRADE_MIN ? throw(Form::GradeTooLowException()) : sign_grade)), _exec_grade(exec_grade < GRADE_MAX ? throw(Form::GradeTooHighException()) : (exec_grade > GRADE_MIN ? throw(Form::GradeTooLowException()) : exec_grade)) { std::cout << "Form" << "\t\t : " << "name:[ " << _name << " ], " << " :  signed:[ " << _signed << " ], sign_grade:[ " << _sign_grade << " ], exec_grade:[ " << _exec_grade << " ]. created !" << std::endl; }
Form::Form(const Form &cpy) : _name(cpy._name), _sign_grade(cpy._sign_grade), _exec_grade(cpy._exec_grade)
{
	*this = cpy;
	std::cout << "Form" << "\t\t : " << "name:[ " << _name << " ], " << "\t :  signed:[ " << _signed << " ], sign_grade:[ " << _sign_grade << " ], exec_grade:[ " << _exec_grade << " ]. cpy created !" << std::endl;
}

Form &Form::operator=(const Form &cpy)
{
	if (this == &cpy)
		return (*this);
	_signed = cpy._signed;
	return (*this);
}

const std::string &Form::getName() const { return (_name); }
int Form::getSignGrade() const { return (_sign_grade); }
int Form::getExecGrade() const { return (_exec_grade); }
bool Form::getSigned() const { return (_signed); }

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	_signed = bureaucrat.getGrade() > _sign_grade ? throw(Form::GradeTooLowException()) : true;
	std::cout << "Form" << "\t\t\t : " << "name:[ " << bureaucrat.getName() << " ], " << " : signed Form:[ " << _name << " ]." << std::endl;
}

const char *Form::GradeTooHighException::what() const throw() { return (GRADE_HIGHT); }
const char *Form::GradeTooLowException::what() const throw() { return (GRADE_LOW); }

std::ostream &operator<<(std::ostream &out, const Form &form) { return (out << "form name:[ " << form.getName() << " ], " << "\t :  signed:[ " << form.getSigned() << " ], sign_grade:[ " << form.getSignGrade() << " ], exec_grade:[ " << form.getExecGrade() << " ]." << std::endl); }
std::ostream &operator<<(std::ostream &out, const Form *form) { return (!form ? out << form : out << *form); }
