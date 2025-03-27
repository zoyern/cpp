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

#include "ClapTrap.hpp"

int main() {
    // Create two ClapTrap instances with Star Wars name
    ClapTrap vader("Darth Vader");
    ClapTrap luke("Luke Skywalker");

    // Display initial status
    std::cout << "\nInitial status:\n";
    vader.attack("Luke Skywalker");
    luke.takeDamage(1);

    // Darth Vader attacks Luke Skywalker several times
    std::cout << "\nDarth Vader attacks Luke Skywalker repeatedly:\n";
    for (int i = 0; i < 5; ++i) {
        vader.attack("Luke Skywalker");
        luke.takeDamage(1);
    }

    // Luke Skywalker repairs himself
    std::cout << "\nLuke Skywalker uses the Force to heal:\n";
    luke.beRepaired(5);

    // Darth Vader runs out of energy
    std::cout << "\nDarth Vader tries to attack but runs out of energy:\n";
    for (int i = 0; i < 10; ++i) {
        vader.attack("Luke Skywalker");
    }

    // Luke Skywalker takes more damage until he dies
    std::cout << "\nLuke Skywalker takes damage until he has no hit points left:\n";
    for (int i = 0; i < 10; ++i) {
        luke.takeDamage(1);
    }

    // Luke Skywalker tries to repair himself with no hit points or energy left
    std::cout << "\nLuke Skywalker tries to heal himself with no hit points or energy left:\n";
    luke.beRepaired(5);

    // End of tests
    std::cout << "\nEnd of tests\n";
    return 0;
}
