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

int main() {
    std::cout << "Creating ClapTrap and ScavTrap instances:" << std::endl;
    
    ClapTrap claptrap("Claptrap");
    ScavTrap scavtrap("Scavtrap");

    std::cout << "\nInitial status and actions:" << std::endl;
    claptrap.attack("target1");
    scavtrap.attack("target2");

    scavtrap.guardGate();
    claptrap.beRepaired(20);
    scavtrap.beRepaired(20);
    scavtrap.takeDamage(20);
    scavtrap.takeDamage(120);
	scavtrap.guardGate();
    return 0;
}