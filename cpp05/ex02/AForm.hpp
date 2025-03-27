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

#ifndef AFORM
	#define AFORM "AFORM"
	#define AFORM_DEFAULT "Default form"
	#define AFORM_DESTROY "Destroyed !"
	#define AFORM_CREATE "Created !!"
	#define AFORM_COPY "Copying ..."
	#define AFORM_CONSTRUCT 1
	#define AFORM_SIGN 50
	#define AFORM_EXEC 25
	#define AFORM_SIGNED false
#endif

#include "Bureaucrat.hpp"

class	Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	size_t				_g_sign;
	size_t				_g_exec;
	bool				_signed;

	void	construct(std::string msg) const;

public:
	class GradeTooHighException : public std::exception	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception	{
	public:
		virtual const char *what() const throw();
	};
	~AForm();
	AForm();
	AForm(const AForm &cpy);
	AForm(const std::string &name, size_t gradeToSign, size_t gradeToExecute);

	AForm &operator=(const AForm &cpy);

	virtual void		execute(const Bureaucrat &executor) const = 0;
	const std::string	&getName() const;
    size_t				getGradeToSign() const;
    size_t				getGradeToExecute() const;
	size_t				checkGrade(size_t grade) const;
	bool				getIsSigned() const;
	void				beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, const AForm &form);
