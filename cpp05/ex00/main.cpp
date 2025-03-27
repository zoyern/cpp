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
    // Test 1: Create a Bureaucrat with a valid grade
	std::cout << "\n-------------------------------------------------------------" << std::endl;
    std::cout << "| Creating a Bureaucrat with a valid grade:" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 2: Create a Bureaucrat with a grade too high
	std::cout << "\n-------------------------------------------------------------" << std::endl;
    std::cout << "| reating a Bureaucrat with a grade too high:" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 0);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 3: Create a Bureaucrat with a grade too low
	std::cout << "\n-------------------------------------------------------------" << std::endl;
    std::cout << "| Creating a Bureaucrat with a grade too low:" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;

    try
    {
        Bureaucrat charlie("Charlie", 151);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 4: Increment and decrement the grade of a Bureaucrat
	std::cout << "\n-------------------------------------------------------------" << std::endl;
    std::cout << "| Incrementing and decrementing the grade of a Bureaucrat:" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
    try
    {
        Bureaucrat dave("Dave", 50);
        std::cout << dave << std::endl;

        dave.upGrade();
        std::cout << "After increment: " << dave << std::endl;

        dave.downGrade();
        std::cout << "After decrement: " << dave << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 5: Increment grade beyond the maximum limit
	std::cout << "\n-------------------------------------------------------------" << std::endl;
    std::cout << "| Incrementing grade beyond the maximum limit:" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
    try
    {
        Bureaucrat eve("Eve", 1);
        std::cout << eve << std::endl;

        eve.upGrade();
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 6: Decrement grade beyond the minimum limit
	std::cout << "\n-------------------------------------------------------------" << std::endl;
    std::cout << "| Decrementing grade beyond the minimum limit:" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
    try
    {
        Bureaucrat frank("Frank", 150);
        std::cout << frank << std::endl;

        frank.downGrade();
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}