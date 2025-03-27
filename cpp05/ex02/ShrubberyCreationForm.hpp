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
#include <fstream>

#include "AForm.hpp"

#ifndef SHRUBBERYCREATIONFORM
	#define SHRUBBERYCREATIONFORM "SHRUBBERYCREATIONFORM"
	#define SHRUBBERYCREATIONFORM_DEFAULT "ShrubberyCreation form"
	#define SHRUBBERYCREATIONFORM_CONSTRUCT 1
	#define SHRUBBERYCREATIONFORM_SIGN 145
	#define SHRUBBERYCREATIONFORM_EXEC 137
#endif

class ShrubberyCreationForm : public AForm
{
private:
	void	construct(std::string msg) const;

public:
	~ShrubberyCreationForm();
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
	ShrubberyCreationForm(const std::string &target);

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &cpy);

	void		execute(const Bureaucrat &executor) const;

};

