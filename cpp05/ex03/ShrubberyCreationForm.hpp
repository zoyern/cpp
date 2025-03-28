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
	#define SHRUBBERYCREATIONFORM "SHRUBBERYCREATION"
	#define SHRUBBERYCREATIONFORM_DEFAULT "ShrubberyCreation form"
	#define SHRUBBERYCREATIONFORM_CONSTRUCT 1
	#define SHRUBBERYCREATIONFORM_SIGN 145
	#define SHRUBBERYCREATIONFORM_EXEC 137
	#define SHRUBBERYCREATIONFORM_SUCCES "\
              _{\\ _{\\{\\/}/}/}__\n\
             {/{/\\}{/{/\\}(\\}{/\\} _\n\
            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n\
         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n\
        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n\
       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n\
      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n\
      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n\
       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n\
        {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n\
	     {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n\
            {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n\
              {){/ {\\/}{\\/} \\}\\}\n\
              (_)  \\.-'.-./\n\
          __...--- |'-.-'| --...__\n\
   _...--'   .-'   |'-.-'|  ' -.  ''--.._\n\
 -'    ' .  . '    |.'-._| '  . .  '    .'\n\
 .  '-  '    .--'  | '-.'|    .  '  . '\n\
          ' ..     |'-_.-|  .   .      .\n\
  .  '  .       _.-|-._ -|-._  .  '  .\n\
              .'   |'- .-|   '.\n\
  ..-'   ' .  '.   `-._.-'   .'  '  - .\n\
   .-' '        '-._______.-'     '  .\n\
    .       .   |\\   .    .   ' '- .\n\
    ___________/  \\____________\n\
  | that is a beautiful tree !! |\n\
   \\___________________________/"
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
