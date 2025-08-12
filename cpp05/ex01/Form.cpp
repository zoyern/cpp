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

Form::~Form() { construct(FORM_DESTROY);}
Form::Form(const Form &cpy) : _name(cpy._name), _g_sign(cpy._g_sign), _g_exec(cpy._g_exec) {*this = cpy; construct(FORM_COPY);}
Form::Form() : _name(FORM_DEFAULT), _g_sign(checkGrade(FORM_SIGN)), _g_exec(checkGrade(FORM_EXEC)), _signed(FORM_SIGNED) { construct(FORM_CREATE);}
Form::Form(const std::string &name, size_t g_sign, size_t g_exec) : _name(name), _g_sign(checkGrade(g_sign)), _g_exec(checkGrade(g_exec)), _signed(FORM_SIGNED) { construct(FORM_CREATE);}
void Form::construct(std::string msg) const { if (FORM_CONSTRUCT) { std::cout << FORM << "\t\t : name:[ " << _name << " ], g_sign : [ " << _g_sign  << " ], g_exec : [ " << _g_exec  << " ]  :" << msg << std::endl;}}

const char *Form::GradeTooHighException::what() const throw() { return (GRADE_HIGHT);}
const char *Form::GradeTooLowException::what() const throw() { return (GRADE_LOW); }

size_t		Form::checkGrade(size_t grade) const { return (
	grade < GRADE_MAX ? throw (GradeTooHighException()) :
	grade > GRADE_MIN ? throw (GradeTooLowException()) :
	grade);
}

Form			&Form::operator=(const Form &cpy){ if (this == &cpy) return (*this);
	return (_signed = checkGrade(cpy._signed), *this);
}

const std::string	&Form::getName() const { return (_name); }
size_t				Form::getGradeToSign() const { return (_g_sign); }
size_t				Form::getGradeToExecute() const { return (_g_exec); }
bool				Form::getIsSigned() const { return (_signed); }
void				Form::beSigned(const Bureaucrat &bureaucrat) { bureaucrat.getGrade() <= _g_sign ? _signed = true : throw (GradeTooLowException());}

std::ostream		&operator<<(std::ostream &out, const Form &form) {
	return (out << "\n" << FORM << "\t\t : info[ name: ( " << form.getName() << " ), GradeToSign :  ( " << form.getGradeToSign()  << " ), GradeToExecute :  ( " << form.getGradeToExecute()  << " ), IsSigned :  ( " << (form.getIsSigned() ? "true" : "false")  << " ) ]."  << std::endl);
}
