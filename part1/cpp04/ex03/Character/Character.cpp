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

#include "Character.hpp"

Character::~Character() { for (size_t i = 0; i < CHARACTERE_INVENTORY; ++i) if (_inventory[i]) delete _inventory[i]; for (size_t i = 0; i < _trash_size; ++i) { if (_trash[i]) delete _trash[i];} if (_trash) delete[] _trash;}
Character::Character() : _name("Guest"), _trash(NULL), _trash_size(0) { for (size_t i = 0; i < CHARACTERE_INVENTORY; ++i) _inventory[i] = NULL;}
Character::Character(std::string name) : _name(name), _trash(NULL), _trash_size(0) { for (size_t i = 0; i < CHARACTERE_INVENTORY; ++i) _inventory[i] = NULL;}
Character::Character(const Character &cpy) : _trash(NULL), _trash_size(0) { for (size_t i = 0; i < CHARACTERE_INVENTORY; ++i) _inventory[i] = NULL; *this = cpy;}

Character			&Character::operator=(const Character &cpy) {
	if (this == &cpy) return (*this);
	_name = cpy._name;
	for (size_t i = 0; i < CHARACTERE_INVENTORY; ++i) {if (_inventory[i]) delete _inventory[i];}
	for (size_t i = 0; i < _trash_size; ++i) {if (_trash && _trash[i]) delete _trash[i]; } if (_trash) delete[] _trash;
	_trash_size = cpy._trash_size;
	_trash = _trash_size > 0 ? new AMateria*[_trash_size]() : NULL;
	for (size_t i = 0; i < CHARACTERE_INVENTORY; ++i) { _inventory[i] = cpy._inventory[i] ? cpy._inventory[i]->clone() : NULL;}
	for (size_t i = 0; i < _trash_size; ++i) { _trash[i] = cpy._trash[i] ? cpy._trash[i]->clone() : NULL;}
	return (*this);
}

std::string const	&Character::getName() const { return (_name);};
void				Character::equip(AMateria *m) {	if (!m) return ; for (size_t i = 0; i < CHARACTERE_INVENTORY; i++) { if (!_inventory[i]) return ((void)(_inventory[i] = m));}};
void				Character::unequip(int idx) { if ((idx < 0 || idx >= CHARACTERE_INVENTORY) || !_inventory[idx])	return ; setTrash(_inventory[idx]); _inventory[idx] = NULL;}
void				Character::setTrash(AMateria *materia) {
	if (!materia) return ;
	AMateria** new_trash = new AMateria*[_trash_size + 1]();
	for (size_t i = 0; i < _trash_size; ++i) { new_trash[i] = _trash[i];} if (_trash) delete[] _trash;
	new_trash[_trash_size++] = materia;
	_trash = new_trash;
};

void				Character::use(int idx, ICharacter& target) { if ((idx < 0 || idx >= CHARACTERE_INVENTORY) || !_inventory[idx]) return ((void)(std::cout << "name:[ " << _name << " ], " << "\t : ??? nothing to use id:[ " << idx << " ], " << std::endl)); _inventory[idx]->use(target);};
