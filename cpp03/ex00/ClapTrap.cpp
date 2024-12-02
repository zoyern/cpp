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

#include "ClapTrap.hpp"

ClapTrap::~ClapTrap() { std::cout <<  PRINT << _name << PRINT_DESTROY << std::endl;}
ClapTrap::ClapTrap() : _name("Unnamed ClapTrap"), _health(HEALTH), _energy(ENERGY), _damage(ATTACK) { std::cout <<  PRINT << _name << PRINT_DEFAULT << std::endl;}
ClapTrap::ClapTrap(std::string name) : _name(name), _health(HEALTH), _energy(ENERGY), _damage(ATTACK) { std::cout <<  PRINT << _name << PRINT_DEFAULT << std::endl;}

void	ClapTrap::attack(const std::string& target) { if (_energy < 1 || _health < 1) return ((void)(std::cout <<  PRINT << _name << " attacks " << target << ", causing " << PRINT_ENERGY_FAIL << std::endl));
	_energy--;
	std::cout <<  PRINT << _name << " attacks " << target << ", causing " << _damage << PRINT_ATTACK << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) { if (_health < 1) return ((void)(std::cout <<  PRINT << _name << " take damage , causing " << PRINT_FAIL << std::endl));
	_health -= amount;
	_health = _health < 0 ? 0 : _health;
	if (_health < 1)
		std::cout <<  PRINT << _name << " is dead... !" << std::endl;
	else
		std::cout <<  PRINT << _name << " take damage , causing " << amount << PRINT_ATTACK << PRINT_HEALTH << _health << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) { if (_energy < 1 || _health < 1) return ((void)(std::cout <<  PRINT << _name << " be repaired , causing " << PRINT_ENERGY_FAIL << std::endl));
	_energy--;
	_health += amount;
	_health = _health > HEALTH ? HEALTH : _health;
	std::cout <<  PRINT << _name << " be repaired , causing " << amount << PRINT_HEAL << PRINT_HEALTH << _health << std::endl;
}