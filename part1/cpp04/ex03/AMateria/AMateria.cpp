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

#include "AMateria.hpp"

AMateria::~AMateria() {}
AMateria::AMateria(std::string type) : _type(type) {}
AMateria::AMateria(const AMateria &cpy) { *this = cpy;}

AMateria			&AMateria::operator=(const AMateria &cpy) { if (this == &cpy) return (*this); _type = cpy._type; return (*this);}

std::string const	&AMateria::getType() const { return (_type);}