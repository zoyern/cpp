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

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm() { construct(AFORM_DESTROY);}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm(cpy) { construct(AFORM_COPY);}
ShrubberyCreationForm::ShrubberyCreationForm() : AForm(SHRUBBERYCREATIONFORM_DEFAULT, SHRUBBERYCREATIONFORM_SIGN, SHRUBBERYCREATIONFORM_EXEC) { construct(AFORM_CREATE);}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(target, SHRUBBERYCREATIONFORM_SIGN, SHRUBBERYCREATIONFORM_EXEC) { construct(AFORM_CREATE);}

void ShrubberyCreationForm::construct(std::string msg) const { if (SHRUBBERYCREATIONFORM_CONSTRUCT) { std::cout << SHRUBBERYCREATIONFORM << "\t\t : name:[ " << getName() << " ], g_sign : [ " << getGradeToSign()  << " ], g_exec : [ " << getGradeToExecute()  << " ]  :" << msg << std::endl;}}

ShrubberyCreationForm		&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpy){ if (this == &cpy) return (*this); return (AForm::operator=(cpy), *this); }

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {(void)executor;}