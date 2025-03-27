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
#include <exception>

#include "Form.hpp"

class	Form;

#ifndef BUREAUCRAT
	#define BUREAUCRAT "BUREAUCRAT"
	#define BUREAUCRAT_DEFAULT "Worker"
	#define BUREAUCRAT_DESTROY "Fired !!"
	#define BUREAUCRAT_CREATE "Recruited !"
	#define BUREAUCRAT_COPY "Copying ..."
	#define BUREAUCRAT_CONSTRUCT 1
#endif

#ifndef GRADE
	#define GRADE 100
	#define GRADE_MAX 1
	#define GRADE_MIN 150
	#define GRADE_HIGHT "Grade is too high!"
	#define GRADE_LOW "Grade is too low!"
#endif

class Bureaucrat
{
private:
	const std::string	_name;
	size_t				_grade;

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
	~Bureaucrat();
	Bureaucrat();
	Bureaucrat(const Bureaucrat &cpy);
	Bureaucrat(std::string name);
	Bureaucrat(size_t grade);
	Bureaucrat(std::string name, int grade);


	Bureaucrat &operator=(const Bureaucrat &cpy);

	const std::string	&getName() const;
	size_t				getGrade() const;
	void				setGrade(size_t grade);
	void				upGrade();
	void				downGrade();
	void				signForm(Form &form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
