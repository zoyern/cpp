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

#ifndef BUREAUCRAT
#define BUREAUCRAT "Worker"
#define GRADE_MAX 1
#define GRADE_MIN 150
#define GRADE_HIGHT "Grade is too high!"
#define GRADE_LOW "Grade is too low!"
#endif

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	~Bureaucrat();
	Bureaucrat();
	Bureaucrat(std::string name);
	Bureaucrat(int grade);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &cpy);

	Bureaucrat &operator=(const Bureaucrat &cpy);

	const std::string &getName() const;
	int getGrade() const;
	void upGrade();
	void downGrade();

	class GradeTooHighException : public std::exception	{public: virtual const char *what() const throw(); };
	class GradeTooLowException : public std::exception {public: virtual const char *what() const throw(); };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
std::ostream &operator<<(std::ostream &out, const Bureaucrat *bureaucrat);
