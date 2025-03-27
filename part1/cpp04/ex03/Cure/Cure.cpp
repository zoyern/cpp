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

#include "Cure.hpp"

Cure::~Cure() {}
Cure::Cure() : AMateria(CURE_TYPE) {}
Cure::Cure(const Cure &cpy) : AMateria(cpy) {}

Cure			&Cure::operator=(const Cure &cpy) {if (this == &cpy) return (*this); AMateria::operator=(cpy); return (*this);}

void		Cure::use(ICharacter &character) {std::cout << CURE_PRINT << "\t\t : " << CURE_ATTACK << " name:[ " << character.getName() << " ], " << CURE_END << std::endl;};
AMateria	*Cure::clone() const { return (new Cure());};