/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:37:34 by marvin            #+#    #+#             */
/*   Updated: 2024/11/22 16:37:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::~FragTrap() { std::cout <<  FRAGTRAP_PRINT << " :\t" << _name << " : " << PRINT_DESTROY << std::endl;}
FragTrap::FragTrap() : ClapTrap("Unnamed FragTrap") { _health = FRAGTRAP_HEALTH, _energy = FRAGTRAP_ENERGY, _damage = FRAGTRAP_DAMAGE; std::cout <<  FRAGTRAP_PRINT << " :\t" << _name << " : " << PRINT_DEFAULT << std::endl;}
FragTrap::FragTrap(std::string name) : ClapTrap(name) { _health = FRAGTRAP_HEALTH, _energy = FRAGTRAP_ENERGY, _damage = FRAGTRAP_DAMAGE; std::cout <<  FRAGTRAP_PRINT << " :\t" << _name << " : " << PRINT_DEFAULT << std::endl;}

void	FragTrap::highFivesGuys() {
	std::string	input;
	do {
		std::cout <<  FRAGTRAP_PRINT << " :\t" << _name  << " : " << " requests a high five [ yes / no ]" << std::endl;
        std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
		if (input.empty() || (input != "yes" && input != "y"))
			std::cout << "Hmmmm.... Sure ?" << std::endl;
	} while (input != "yes" && input != "y");
	std::cout << "Hey hey hey Yeeeaaaahhh.... GIGA HIGHT FIVES !!" << std::endl;
}
