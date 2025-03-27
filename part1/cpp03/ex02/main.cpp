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

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "Creating ClapTrap, ScavTrap, and FragTrap instances:" << std::endl;
    ClapTrap clap("Claptrap");
    ScavTrap scav("Scavtrap");
    FragTrap frag("Fragtrap");

    std::cout << "\nInitial status and actions:" << std::endl;
    clap.attack("target1");
    scav.attack("target2");
    scav.guardGate();
    frag.attack("target3");
    frag.highFivesGuys();

    std::cout << "\nPerforming actions:" << std::endl;
    clap.beRepaired(20);
    scav.beRepaired(20);
    frag.beRepaired(20);

    std::cout << "\nDestruction sequence:" << std::endl;
    // Destructor messages will be printed automatically when objects go out of scope

    return 0;
}