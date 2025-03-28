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

Bureaucrat::~Bureaucrat() { construct(BUREAUCRAT_DESTROY);}
Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : _name(cpy._name) {*this = cpy; construct(BUREAUCRAT_COPY);}
Bureaucrat::Bureaucrat() : _name(BUREAUCRAT_DEFAULT), _grade(checkGrade(GRADE)) { construct(BUREAUCRAT_CREATE);}
Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(checkGrade(GRADE))  { construct(BUREAUCRAT_CREATE); }
Bureaucrat::Bureaucrat(size_t grade) : _name(BUREAUCRAT_DEFAULT), _grade(checkGrade(grade)){ construct(BUREAUCRAT_CREATE); }
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(checkGrade(grade)){ construct(BUREAUCRAT_CREATE);}
void Bureaucrat::construct(std::string msg) const {	if (BUREAUCRAT_CONSTRUCT) { std::cout << BUREAUCRAT << "\t\t : name:[ " << _name << " ], grade : [ " << _grade  << " ]  :" << msg << std::endl;}}

const char *Bureaucrat::GradeTooHighException::what() const throw() { return (EXEPTION_TOOHIGHT);}
const char *Bureaucrat::GradeTooLowException::what() const throw() { return (EXEPTION_TOOLOW); }

size_t		Bureaucrat::checkGrade(size_t grade) const { return (
	grade < GRADE_MAX ? throw GradeTooHighException() :
	grade > GRADE_MIN ? throw GradeTooLowException() :
	grade);
}

Bureaucrat			&Bureaucrat::operator=(const Bureaucrat &cpy){ if (this == &cpy) return (*this); return (_grade = checkGrade(cpy._grade), *this);}

const std::string	&Bureaucrat::getName() const { return (_name); }
size_t				Bureaucrat::getGrade() const { return (_grade); }
void				Bureaucrat::setGrade(size_t grade) { _grade = checkGrade(grade); }
void				Bureaucrat::upGrade(){	_grade = checkGrade(_grade - 1);}
void				Bureaucrat::downGrade(){ _grade = checkGrade(_grade + 1);}
void				Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
        std::cout << *this << "HAVE SIGNED :" << form << std::endl;
    } catch (const AForm::GradeTooLowException &e) {
        std::cout << *this << "COULDN'T SIGN :" << form << "\nREASON :\n" << e.what() << std::endl;
    }
}
void				Bureaucrat::executeForm(const AForm &form) const {
	try {
        form.execute(*this);
		std::cout << *this << "HAVE EXECUTED :" << form << std::endl;
    } catch (const AForm::GradeTooLowException &e) {
		std::cout << *this << "COULDN'T EXECUTE :" << form << "\nREASON :\n" << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cout << *this << "Encountered an error while executing " << form.getName() << ": " << e.what() << std::endl;
    }
}

std::ostream		&operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	return (out << "\n" << BUREAUCRAT << "\t\t : info[ name: ( " << bureaucrat.getName() << " ) , grade :  ( " << bureaucrat.getGrade()  << " ) ]."  << std::endl);
}
