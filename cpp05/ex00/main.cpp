/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:36:29 by marvin            #+#    #+#             */
/*   Updated: 2024/11/22 16:36:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat();
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << "hey\n";
		std::cout << a;
		std::cout << "hey\n";

		try
		{
			a->upGrade();
		}
		catch (Bureaucrat::GradeTooHighException &e) // the try-catch blocks inside the class are commented out but fully functional
		{
			std::cerr << "\033[33mIncrementing grade of " << a->getName() << " failed: " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << a;
		try
		{
			a->downGrade();
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33mDecrementing grade of " << a->getName() << " failed: " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << a;

		try
		{
			a->downGrade();
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33mDecrementing grade of " << a->getName() << " failed: " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << a;
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat(1);
		std::cout << std::endl;
		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;

		try
		{
			a->downGrade();
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33mDecrementing grade of " << a->getName() << " failed: " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << a;

		try
		{
			a->upGrade();
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "\033[33mIncrementing grade of " << a->getName() << " failed: " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << a;

		try
		{
			a->upGrade();
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "\033[33mIncrementing grade of " << a->getName() << " failed: " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << a;
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = NULL;

		try
		{
			a = new Bureaucrat(0);
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " << e.what() << "\033[0m" << std::endl;
		}

		if (a != NULL)
		{
			std::cout << std::endl;

			std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
			delete a;
		}

		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = NULL;

		try
		{
			a = new Bureaucrat(160);
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " << e.what() << "\033[0m" << std::endl;
		}

		if (a != NULL)
		{
			std::cout << std::endl;
			std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
			delete a;
		}
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Peter", 120);
		std::cout << std::endl;

		std::cout << "\033[34mTesting a\033[0m" << std::endl;
		std::cout << a;

		a->downGrade();

		std::cout << a;
		std::cout << std::endl;

		std::cout << "\033[34mConstructing b\033[0m" << std::endl;
		Bureaucrat *b = new Bureaucrat(*a);
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing a\033[0m" << std::endl;
		delete a;
		std::cout << std::endl;

		std::cout << "\033[34mTesting b\033[0m" << std::endl;
		std::cout << b;
		b->downGrade();
		std::cout << b;
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
		delete b;

		std::cout << std::endl;
	}
}