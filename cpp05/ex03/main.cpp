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

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <fstream>

int main() {
    Intern intern;

    try {
        // Test 1: Création de formulaires valides
        AForm* shrubberyForm = intern.makeForm("shrubbery creation", "Home");
        std::cout << "Created: " << shrubberyForm->getName() << std::endl;
		delete shrubberyForm;

        AForm* robotomyForm = intern.makeForm("robotomy request", "Office");
        std::cout << "Created: " << robotomyForm->getName() << std::endl;
		delete robotomyForm;

        AForm* pardonForm = intern.makeForm("presidential pardon", "Friend");
        std::cout << "Created: " << pardonForm->getName() << std::endl;
		delete pardonForm;

        // Test 2: Nom de formulaire invalide
        try {
            intern.makeForm("unknown form", "Nowhere");
        } catch (const Intern::FormNameError& e) {
            std::cerr << "Form Name Error ( unknown form ) : " << e.what() << std::endl;
        }

        // Test 3: Autre nom de formulaire invalide
        try {
            intern.makeForm("invalid form name", "Somewhere");
        } catch (const Intern::FormNameError& e) {
            std::cerr << "Form Name Error (invalid form name) : " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
