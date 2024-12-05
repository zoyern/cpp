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

Ice::Ice() : AMateria(ICE_TYPE) {}

void		Ice::use(ICharacter &character) {std::cout << ICE_PRINT << "\t : " << ICE_ATTACK << " name:[ " << character.getName() << " ], " << ICE_END << std::endl;};
AMateria	*Ice::clone() const { return (new Ice());};