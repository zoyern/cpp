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

#include "ScavTrap.hpp"

ScavTrap::~ScavTrap() { std::cout <<  SCAVTRAP_PRINT << " :\t" << _name << " : " << PRINT_DESTROY << std::endl;}
ScavTrap::ScavTrap() : ClapTrap("Unnamed ScavTrap"), _guardGate(false) { _health = SCAVTRAP_HEALTH, _energy = SCAVTRAP_ENERGY, _damage = SCAVTRAP_DAMAGE; std::cout <<  SCAVTRAP_PRINT << " :\t" << _name << " : " << PRINT_DEFAULT << std::endl;}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _guardGate(false) { _health = SCAVTRAP_HEALTH, _energy = SCAVTRAP_ENERGY, _damage = SCAVTRAP_DAMAGE; std::cout <<  SCAVTRAP_PRINT << " :\t" << _name << " : " << PRINT_DEFAULT << std::endl;}
ScavTrap::ScavTrap(const ScavTrap &cpy) : ClapTrap(cpy), _guardGate(false) { *this = cpy;}

ScavTrap	&ScavTrap::operator=(const ScavTrap &cpy) { if (this == &cpy) return (*this); 
	ClapTrap::operator=(cpy);
	_guardGate = cpy._guardGate;
	return (*this);
}

void	ScavTrap::attack(const std::string& target) { 
	if (_energy < 1 || _health < 1)
		return ((void)(std::cout << SCAVTRAP_PRINT << " :\t" << _name << " : "  << " attacks " << target << ", causing " << PRINT_FAIL << std::endl));
	_energy--;
	std::cout << SCAVTRAP_PRINT << " :\t" << _name << " : "  << " attacks " << target << ", causing [ " << _damage  << " ] " << SCAVTRAP_ATTACK << " health:[ " << _health  << " / " << SCAVTRAP_HEALTH << " ] " << "energy:[ " << _energy  << " / " << SCAVTRAP_ENERGY << " ] " << std::endl;
}

void ScavTrap::guardGate() { _guardGate = !_guardGate;
	if (_guardGate)
    	std::cout <<  SCAVTRAP_PRINT << " :\t" << _name << " : " << " is now in Gate Keeper mode" << std::endl;
	else
    	std::cout <<  SCAVTRAP_PRINT << " :\t" << _name << " : " << " is no longer in Gate Keeper mode" << std::endl;
}