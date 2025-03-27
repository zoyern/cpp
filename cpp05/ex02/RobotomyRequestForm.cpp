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


#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm() { construct(AFORM_DESTROY);}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm(cpy) { construct(AFORM_COPY);}
RobotomyRequestForm::RobotomyRequestForm() : AForm(ROBOTOMYREQUESTFORM_DEFAULT, ROBOTOMYREQUESTFORM_SIGN, ROBOTOMYREQUESTFORM_EXEC) { construct(AFORM_CREATE);}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm(target, ROBOTOMYREQUESTFORM_SIGN, ROBOTOMYREQUESTFORM_EXEC) { construct(AFORM_CREATE);}

void RobotomyRequestForm::construct(std::string msg) const { if (ROBOTOMYREQUESTFORM_CONSTRUCT) { std::cout << ROBOTOMYREQUESTFORM << "\t\t : name:[ " << getName() << " ], g_sign : [ " << getGradeToSign()  << " ], g_exec : [ " << getGradeToExecute()  << " ]  :" << msg << std::endl;}}

RobotomyRequestForm		&RobotomyRequestForm::operator=(const RobotomyRequestForm &cpy){ if (this == &cpy) return (*this); return (AForm::operator=(cpy), *this); }

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {(void)executor;}