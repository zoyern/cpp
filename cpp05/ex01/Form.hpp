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

#ifndef FORM
#define FORM "Form"
#define FORM_SIGN GRADE_MIN
#define FORM_EXEC GRADE_MIN
#define GRADE_HIGHT "Grade is too high!"
#define GRADE_LOW "Grade is too low!"
#endif

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _sign_grade;
	const int _exec_grade;

public:
	~Form();
	Form();
	Form(std::string name);
	Form(std::string name, int sign_grade, int exec_grade);
	Form(int sign_grade, int exec_grade);
	Form(const Form &cpy);

	Form &operator=(const Form &cpy);

	void beSigned(const Bureaucrat &bureaucrat);
	const std::string &getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool getSigned() const;

	class GradeTooHighException	: public std::exception	{ public: virtual const char *what() const throw();};
	class GradeTooLowException	: public std::exception	{ public: virtual const char *what() const throw();};
};

std::ostream &operator<<(std::ostream &out, const Form &form);
std::ostream &operator<<(std::ostream &out, const Form *form);
