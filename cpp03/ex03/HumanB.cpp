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

#include "HumanB.hpp"

HumanB::~HumanB() {}
HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}
void		HumanB::attack() { std::cout << _name << " attacks with their " << (_weapon ? _weapon->getType() : W_DEFAULT) << std::endl;}
void		HumanB::setWeapon(Weapon *weapon) { _weapon = weapon;}