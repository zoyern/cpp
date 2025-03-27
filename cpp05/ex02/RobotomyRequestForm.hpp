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

#include "AForm.hpp"


#ifndef ROBOTOMYREQUESTFORM
	#define ROBOTOMYREQUESTFORM "ROBOTOMYREQUESTFORM"
	#define ROBOTOMYREQUESTFORM_DEFAULT "RobotomyRequest form"
	#define ROBOTOMYREQUESTFORM_CONSTRUCT 1
	#define ROBOTOMYREQUESTFORM_SIGN 72
	#define ROBOTOMYREQUESTFORM_EXEC 45
#endif

class RobotomyRequestForm : public AForm
{
private:
	void	construct(std::string msg) const;

public:
	~RobotomyRequestForm();
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &cpy);
	RobotomyRequestForm(const std::string &target);

	RobotomyRequestForm	&operator=(const RobotomyRequestForm &cpy);

	void	execute(const Bureaucrat &executor) const;
};
