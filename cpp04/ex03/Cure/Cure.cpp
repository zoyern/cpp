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

#include "cure.hpp"

Cure::Cure() : AMateria(CURE_TYPE) {}

void		Cure::use(ICharacter &character) {std::cout << CURE_PRINT << "\t : " << CURE_ATTACK << " name:[ " << character.getName() << " ], " << CURE_END << std::endl;};
AMateria	*Cure::clone() const { return (new Cure());};