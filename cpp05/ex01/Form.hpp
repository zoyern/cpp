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

#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class	Bureaucrat;

#ifndef FORM
	#define FORM "FORM"
	#define FORM_DEFAULT "Default form"
	#define FORM_DESTROY "Destroyed !"
	#define FORM_CREATE "Created !!"
	#define FORM_COPY "Copying ..."
	#define FORM_CONSTRUCT 1
	#define FORM_SIGN 50
	#define FORM_EXEC 25
	#define FORM_SIGNED false
#endif

class Form
{
private:
	const std::string	_name;
	size_t				_g_sign;
	size_t				_g_exec;
	bool				_signed;

	void	construct(std::string msg) const;
	size_t	checkGrade(size_t grade) const;

public:
	class GradeTooHighException : public std::exception	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception	{
	public:
		virtual const char *what() const throw();
	};
	~Form();
	Form();
	Form(const Form &cpy);
	Form(const std::string &name, size_t gradeToSign, size_t gradeToExecute);

	Form &operator=(const Form &cpy);

	const std::string	&getName() const;
    size_t				getGradeToSign() const;
    size_t				getGradeToExecute() const;
	bool				getIsSigned() const;
	void				beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, const Form &form);
