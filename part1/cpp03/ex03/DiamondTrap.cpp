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

#include "DiamondTrap.hpp"

DiamondTrap::~DiamondTrap() { std::cout <<  DIAMONDTRAP_PRINT << " :\t" << _name << " : " << PRINT_DESTROY << std::endl;}
DiamondTrap::DiamondTrap() : ClapTrap("Unnamed_clap_name"), _name("Unnamed DiamondTrap") { _health = FragTrap::_health, _energy = ScavTrap::_energy, _damage = FragTrap::_damage; std::cout <<  DIAMONDTRAP_PRINT << " :\t" << _name << " : " << PRINT_DEFAULT << std::endl;}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name) { _health = FragTrap::_health, _energy = ScavTrap::_energy, _damage = FragTrap::_damage; std::cout <<  DIAMONDTRAP_PRINT << " :\t" << _name << " : " << PRINT_DEFAULT << std::endl;}
DiamondTrap::DiamondTrap(const DiamondTrap &cpy) : ClapTrap(cpy), ScavTrap(cpy), FragTrap(cpy) { *this = cpy;}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &cpy) { if (this == &cpy) return (*this); 
	ScavTrap::operator=(cpy);
	_name = cpy._name;
	return (*this);
}

void	DiamondTrap::attack(const std::string& target) { ScavTrap::attack(target);}

void	DiamondTrap::whoAmI() { std::cout <<  DIAMONDTRAP_PRINT << " :\t" << _name  << " : " << "Hello i am a DiamondTrap named:[ " << _name  << " ] " << " and i am originated from the ClapTrap named:[ " << ClapTrap::_name << " ] " << std::endl;}