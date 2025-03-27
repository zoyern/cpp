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

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm() { construct(AFORM_DESTROY);}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : AForm(cpy) { construct(AFORM_COPY);}
PresidentialPardonForm::PresidentialPardonForm() : AForm(PRESIDENTIALPARDONFORM_DEFAULT, PRESIDENTIALPARDONFORM_SIGN, PRESIDENTIALPARDONFORM_EXEC) { construct(AFORM_CREATE);}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm(target, PRESIDENTIALPARDONFORM_SIGN, PRESIDENTIALPARDONFORM_EXEC) { construct(AFORM_CREATE);}

void PresidentialPardonForm::construct(std::string msg) const { if (PRESIDENTIALPARDONFORM_CONSTRUCT) { std::cout << PRESIDENTIALPARDONFORM << "\t\t : name:[ " << getName() << " ], g_sign : [ " << getGradeToSign()  << " ], g_exec : [ " << getGradeToExecute()  << " ]  :" << msg << std::endl;}}

PresidentialPardonForm		&PresidentialPardonForm::operator=(const PresidentialPardonForm &cpy){ if (this == &cpy) return (*this); return (AForm::operator=(cpy), *this); }

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {(void)executor;}