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

#include "MateriaSource.hpp"

MateriaSource::~MateriaSource() { for (size_t i = 0; i < MATERIASOURCE_INVENTORY; ++i) if (_inventory[i]) delete _inventory[i];}
MateriaSource::MateriaSource() { for (size_t i = 0; i < MATERIASOURCE_INVENTORY; ++i) _inventory[i] = NULL;}

void		MateriaSource::learnMateria(AMateria *materia) { if (!materia) return ; for (size_t i = 0; i < MATERIASOURCE_INVENTORY; i++) if (!_inventory[i]) return ((void)(_inventory[i] = materia));};
AMateria	*MateriaSource::createMateria(std::string const &type) { for (size_t i = 0; i < MATERIASOURCE_INVENTORY; i++) if (_inventory[i] && _inventory[i]->getType() == type) return (_inventory[i]->clone()); return (0);};