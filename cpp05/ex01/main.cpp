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
#include "Form.hpp"

int main() {
    // Test 1: Create a Bureaucrat and a Form with valid grades
    try {
        Bureaucrat bob("Bob", 50);
        Form form1("Form1", 50, 50);
        std::cout << bob << std::endl;
        std::cout << form1 << std::endl;

        // Test 2: Bureaucrat signs the Form successfully
        bob.signForm(form1);
        std::cout << form1 << std::endl;
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

    // Test 5: Create a Form with a grade too high
    try {
        Form formHigh("FormHigh", 0, 50);
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 6: Create a Form with a grade too low
    try {
        Form formLow("FormLow", 151, 50);
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 7: Bureaucrat tries to sign a Form with insufficient grade
    try {
        Bureaucrat dave("Dave", 100);
        Form form2("Form2", 40, 50);
        std::cout << dave << std::endl;
        std::cout << form2 << std::endl;

        dave.signForm(form2);
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 8: Bureaucrat signs a Form after incrementing grade
    try {
        Bureaucrat eve("Eve", 40);
        Form form3("Form3", 40, 50);
        std::cout << eve << std::endl;
        std::cout << form3 << std::endl;

        eve.upGrade();
        eve.signForm(form3);
        std::cout << form3 << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 9: Bureaucrat tries to sign a Form after decrementing grade
    try {
        Bureaucrat frank("Frank", 39);
        Form form4("Form4", 40, 50);
        std::cout << frank << std::endl;
        std::cout << form4 << std::endl;

        frank.downGrade();
        frank.signForm(form4);
        std::cout << form4 << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 10: Bureaucrat tries to sign a Form with exactly the required grade
    try {
        Bureaucrat grace("Grace", 40);
        Form form5("Form5", 40, 50);
        std::cout << grace << std::endl;
        std::cout << form5 << std::endl;

        grace.signForm(form5);
        std::cout << form5 << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 11: Bureaucrat tries to sign a Form after multiple increments
    try {
        Bureaucrat heidi("Heidi", 45);
        Form form6("Form6", 40, 50);
        std::cout << heidi << std::endl;
        std::cout << form6 << std::endl;

        heidi.upGrade();
        heidi.upGrade();
        heidi.signForm(form6);
        std::cout << form6 << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 12: Bureaucrat tries to sign a Form after multiple decrements
    try {
        Bureaucrat ivan("Ivan", 35);
        Form form7("Form7", 40, 50);
        std::cout << ivan << std::endl;
        std::cout << form7 << std::endl;

        ivan.downGrade();
        ivan.downGrade();
        ivan.signForm(form7);
        std::cout << form7 << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
