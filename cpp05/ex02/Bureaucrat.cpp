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

#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat() { std::cout << "Bureaucrat" << "\t : " << "name:[ " << _name << " ], " << "grade:[ " << _grade << " ], destroyed !" << std::endl; }
Bureaucrat::Bureaucrat() : _name(BUREAUCRAT), _grade(GRADE_MIN) { std::cout << "Bureaucrat" << "\t : " << "name:[ " << _name << " ], " << "grade:[ " << _grade << " ], created !" << std::endl; }
Bureaucrat::Bureaucrat(int grade) : _name(BUREAUCRAT), _grade(grade < GRADE_MAX ? throw(Bureaucrat::GradeTooHighException()) : (grade > GRADE_MIN ? throw(Bureaucrat::GradeTooLowException()) : grade)) { std::cout << "Bureaucrat" << "\t : " << "name:[ " << _name << " ], " << "grade:[ " << _grade << " ], created !" << std::endl; }
Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(GRADE_MIN) { std::cout << "Bureaucrat" << "\t : " << "name:[ " << _name << " ], " << "grade:[ " << _grade << " ], created !" << std::endl; }
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade < GRADE_MAX ? throw(Bureaucrat::GradeTooHighException()) : (grade > GRADE_MIN ? throw(Bureaucrat::GradeTooLowException()) : grade)) { std::cout << "Bureaucrat" << "\t : " << "name:[ " << _name << " ], " << "grade:[ " << _grade << " ], created !" << std::endl; }
Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : _name(cpy._name)
{
	*this = cpy;
	std::cout << "Bureaucrat" << "\t\t : " << "name:[ " << _name << " ], " << "grade:[ " << _grade << " ], cpy created !" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cpy)
{
	if (this == &cpy)
		return (*this);
	_grade = cpy._grade;
	return (*this);
}

const std::string &Bureaucrat::getName() const { return (_name); }
void Bureaucrat::upGrade()
{
	_grade--;
	if (_grade < GRADE_MAX)
		throw(_grade++, Bureaucrat::GradeTooHighException());
}
void Bureaucrat::downGrade()
{
	_grade++;
	if (_grade > GRADE_MIN)
		throw(_grade--, Bureaucrat::GradeTooLowException());
}

int Bureaucrat::getGrade() const { return (_grade); }

void Bureaucrat::signForm(AForm &form)
{
	try	{form.beSigned(*this);}
	catch (AForm::GradeTooLowException &e){	throw(Bureaucrat::GradeTooLowException());}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() { return (GRADE_HIGHT); }
const char *Bureaucrat::GradeTooLowException::what() const throw() { return (GRADE_LOW); }

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) { return (out << "name:[ " << bureaucrat.getName() << " ], " << "\t :  bureaucrat grade grade:[ " << bureaucrat.getGrade() << " ]." << std::endl); }
std::ostream &operator<<(std::ostream &out, const Bureaucrat *bureaucrat) { return (!bureaucrat ? out << bureaucrat : out << *bureaucrat); }
