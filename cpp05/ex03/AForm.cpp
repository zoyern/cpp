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

AForm::~AForm() { construct(AFORM_DESTROY);}
AForm::AForm(const AForm &cpy) : _name(cpy._name) {*this = cpy; construct(AFORM_COPY);}
AForm::AForm() : _name(AFORM_DEFAULT), _g_sign(checkGrade(AFORM_SIGN)), _g_exec(checkGrade(AFORM_EXEC)), _signed(AFORM_SIGNED) { construct(AFORM_CREATE);}
AForm::AForm(const std::string &name, size_t g_sign, size_t g_exec) : _name(name), _g_sign(checkGrade(g_sign)), _g_exec(checkGrade(g_exec)), _signed(AFORM_SIGNED) { construct(AFORM_CREATE);}
void AForm::construct(std::string msg) const { if (AFORM_CONSTRUCT) { std::cout << AFORM << "\t\t\t : name:[ " << _name << " ], g_sign : [ " << _g_sign  << " ], g_exec : [ " << _g_exec  << " ]  :" << msg << std::endl;}}

const char *AForm::GradeTooHighException::what() const throw() { return (EXEPTION_TOOHIGHT);}
const char *AForm::GradeTooLowException::what() const throw() { return (EXEPTION_TOOLOW); }
const char *AForm::FormNotSignedException::what() const throw() { return (EXEPTION_NOTSIGN); }
const char *AForm::ExecuteErrorException::what() const throw() { return (EXEPTION_NOTEXEC); }

size_t		AForm::checkGrade(size_t grade) const { return (checkGrade(grade, GRADE_MIN), grade);}
bool		AForm::checkGrade(size_t grade, size_t grade_min) const { return (
	grade < GRADE_MAX ? throw (GradeTooHighException()) :
	grade > grade_min ? throw (GradeTooLowException()) :
	getIsSigned());
}

AForm			&AForm::operator=(const AForm &cpy){ if (this == &cpy) return (*this);
	return (
		_g_sign = checkGrade(cpy._g_sign),
		_g_exec = checkGrade(cpy._g_exec),
		_signed = checkGrade(cpy._signed),
		*this);
}

const std::string	&AForm::getName() const { return (_name); }
size_t				AForm::getGradeToSign() const { return (_g_sign); }
size_t				AForm::getGradeToExecute() const { return (_g_exec); }
bool				AForm::getIsSigned() const { return (_signed); }
void				AForm::beSigned(const Bureaucrat &bureaucrat) { checkGrade(bureaucrat.getGrade(), getGradeToSign()), _signed = true;}

std::ostream		&operator<<(std::ostream &out, const AForm &form) {
	return (out << "\n" << AFORM << "\t\t\t : info[ name: ( " << form.getName() << " ), GradeToSign :  ( " << form.getGradeToSign()  << " ), GradeToExecute :  ( " << form.getGradeToExecute()  << " ), IsSigned :  ( " << (form.getIsSigned() ? "true" : "false")  << " ) ]."  << std::endl);
}
