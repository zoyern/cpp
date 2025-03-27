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

#include "Ice.hpp"

Ice::~Ice() {}
Ice::Ice() : AMateria(ICE_TYPE) {}
Ice::Ice(const Ice &cpy) : AMateria(cpy) {}

Ice			&Ice::operator=(const Ice &cpy) {if (this == &cpy) return (*this); AMateria::operator=(cpy); return (*this);}

void		Ice::use(ICharacter &character) {std::cout << ICE_PRINT << "\t\t : " << ICE_ATTACK << " name:[ " << character.getName() << " ], " << ICE_END << std::endl;};
AMateria	*Ice::clone() const { return (new Ice());};