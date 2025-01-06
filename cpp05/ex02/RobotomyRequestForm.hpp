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
#include "AForm.hpp"

#ifndef RRFORM
#define RRFORM "RobotomyRequestForm"
#define RRFORM_SIGN GRADE_MIN
#define RRFORM_EXEC GRADE_MIN
#define GRADE_HIGHT "Grade is too high!"
#define GRADE_LOW "Grade is too low!"
#endif

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
public:
	~RobotomyRequestForm();
	RobotomyRequestForm();
	RobotomyRequestForm(std::string name);
	RobotomyRequestForm(std::string name, int sign_grade, int exec_grade);
	RobotomyRequestForm(int sign_grade, int exec_grade);
	RobotomyRequestForm(const RobotomyRequestForm &cpy);

	RobotomyRequestForm &operator=(const RobotomyRequestForm &cpy);

	void beSigned(const Bureaucrat &bureaucrat);
	const std::string &getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool getSigned() const;

	class GradeTooHighException	: public std::exception	{ public: virtual const char *what() const throw();};
	class GradeTooLowException	: public std::exception	{ public: virtual const char *what() const throw();};
};

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &form);
std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm *form);
