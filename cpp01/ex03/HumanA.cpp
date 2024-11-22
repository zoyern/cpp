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

#include "HumanA.hpp"

HumanA::~HumanA() {}
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {}
void		HumanA::attack() { std::cout << _name << ATTACK << _weapon.getType() << std::endl;}