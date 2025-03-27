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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <fstream>

int main() {
    // Test 1: Create a Bureaucrat and different forms with valid grades
    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm shrubbery("Home");
        RobotomyRequestForm robotomy("Office");
        PresidentialPardonForm pardon("Friend");

        std::cout << bob << std::endl;
        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        // Test 2: Bureaucrat signs and executes the forms successfully
        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);

        bob.signForm(robotomy);
        bob.executeForm(robotomy);

        bob.signForm(pardon);
        bob.executeForm(pardon);
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 3: Create a Bureaucrat with a grade too high
    try {
        Bureaucrat alice("Alice", 0);
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 4: Create a Bureaucrat with a grade too low
    try {
        Bureaucrat charlie("Charlie", 151);
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 5: Create forms with invalid grades
    try {
        ShrubberyCreationForm invalidShrubbery("Invalid");
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        RobotomyRequestForm invalidRobotomy("Invalid");
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        PresidentialPardonForm invalidPardon("Invalid");
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 6: Bureaucrat tries to sign and execute a form with insufficient grade
    try {
        Bureaucrat dave("Dave", 100);
        ShrubberyCreationForm shrubbery("Park");

        std::cout << dave << std::endl;
        std::cout << shrubbery << std::endl;

        dave.signForm(shrubbery);
        dave.executeForm(shrubbery);
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 7: Bureaucrat signs and executes a form after incrementing grade
    try {
        Bureaucrat eve("Eve", 146);
        ShrubberyCreationForm shrubbery("Garden");

        std::cout << eve << std::endl;
        std::cout << shrubbery << std::endl;

        eve.upGrade();
        eve.signForm(shrubbery);
        eve.executeForm(shrubbery);
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 8: Bureaucrat tries to execute a form without signing it
    try {
        Bureaucrat frank("Frank", 1);
        ShrubberyCreationForm shrubbery("Yard");

        std::cout << frank << std::endl;
        std::cout << shrubbery << std::endl;

        frank.executeForm(shrubbery);
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 9: Bureaucrat executes a form after signing it
    try {
        Bureaucrat grace("Grace", 1);
        ShrubberyCreationForm shrubbery("Field");

        std::cout << grace << std::endl;
        std::cout << shrubbery << std::endl;

        grace.signForm(shrubbery);
        grace.executeForm(shrubbery);
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

