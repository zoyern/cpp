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

ClapTrap::~ClapTrap() { std::cout << CLAPTRAP_PRINT << " :\t" << _name << " : " << PRINT_DESTROY << std::endl;}
ClapTrap::ClapTrap() : _name("Unnamed ClapTrap"), _health(CLAPTRAP_HEALTH), _energy(CLAPTRAP_ENERGY), _damage(CLAPTRAP_DAMAGE) { std::cout <<  CLAPTRAP_PRINT << " :\t" << _name << " : " << PRINT_DEFAULT << std::endl;}
ClapTrap::ClapTrap(std::string name) : _name(name), _health(CLAPTRAP_HEALTH), _energy(CLAPTRAP_ENERGY), _damage(CLAPTRAP_DAMAGE) { std::cout <<  CLAPTRAP_PRINT << " :\t" << _name << " : "  << PRINT_DEFAULT << std::endl;}
ClapTrap::ClapTrap(const ClapTrap &cpy) { *this = cpy;}

ClapTrap	&ClapTrap::operator=(const ClapTrap &cpy) { if (this == &cpy) return (*this); 
	_name = cpy._name;
	_health = cpy._health;
	_energy = cpy._energy;
	_damage = cpy._damage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target) { 
	if (_energy < 1 || _health < 1)
		return ((void)(std::cout << CLAPTRAP_PRINT << " :\t" << _name << " : "  << " attacks " << target << ", causing " << PRINT_FAIL << std::endl));
	_energy--;
	std::cout << CLAPTRAP_PRINT << " :\t" << _name << " : "  << " attacks " << target << ", causing [ " << _damage  << " ] " << CLAPTRAP_ATTACK << " health:[ " << _health  << " / " << CLAPTRAP_HEALTH << " ] " << "energy:[ " << _energy  << " / " << CLAPTRAP_ENERGY << " ] " << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_health < 1)
		return ((void)(std::cout << CLAPTRAP_PRINT << " :\t" << _name << " : "  << " take damage , causing " << PRINT_DEATH << std::endl));
	_health -= amount;
	_health = _health < 0 ? 0 : _health;
	if (_health < 1)
		std::cout << CLAPTRAP_PRINT << " :\t" << _name << " : "  << " take damage , causing [ " << amount  << " ] of damage " << "and die..." << " heath:[ " << _health << " ] " << std::endl;
	else
		std::cout << CLAPTRAP_PRINT << " :\t" << _name  << " : " << " take damage , causing [ " << amount  << " ] of damage " << "heath:[ " << _health << " ] " << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_energy < 1 || _health < 1)
		return ((void)(std::cout <<  CLAPTRAP_PRINT << " :\t" << _name  << " : " << " be repaired , causing " << PRINT_FAIL << std::endl));
	_energy--;
	_health += amount;
	std::cout <<  CLAPTRAP_PRINT << " :\t" << _name  << " : " << " be repaired , causing [ " << amount  << " ] " << PRINT_HEAL << " health:[ " << _health << " ] " << " energy:[ " << _energy << " ] " << std::endl;
}