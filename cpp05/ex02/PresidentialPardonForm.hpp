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

#ifndef PRESIDENTIALPARDONFORM
	#define PRESIDENTIALPARDONFORM "PRESIDENTIALPARDONFORM"
	#define PRESIDENTIALPARDONFORM_DEFAULT "PresidentialPardon form"
	#define PRESIDENTIALPARDONFORM_CONSTRUCT 1
	#define PRESIDENTIALPARDONFORM_SIGN 25
	#define PRESIDENTIALPARDONFORM_EXEC 5
#endif

class PresidentialPardonForm : public AForm
{
private:
	void	construct(std::string msg) const;

public:
	~PresidentialPardonForm();
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &cpy);
	PresidentialPardonForm(const std::string &target);

	PresidentialPardonForm &operator=(const PresidentialPardonForm &cpy);

	void		execute(const Bureaucrat &executor) const;
};
