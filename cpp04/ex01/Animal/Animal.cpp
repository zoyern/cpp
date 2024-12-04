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

#include "Animal.hpp"

Animal::~Animal() { std::cout << ANIMAL_PRINT << "\t : " << "type:[ " << _type << " ], " << ANIMAL_DESTROY << std::endl;}
Animal::Animal() : _type(ANIMAL_TYPE) { std::cout << ANIMAL_PRINT << "\t : " << "type:[ " << _type << " ], " << ANIMAL_DEFAULT << std::endl;}
Animal::Animal(std::string type) : _type(type) { std::cout << ANIMAL_PRINT << "\t : " << "type:[ " << _type << " ], " << ANIMAL_DEFAULT << std::endl;}
Animal::Animal(const Animal &animal) : _type(animal.getType()) { std::cout << ANIMAL_PRINT << "\t : " << "type:[ " << _type << " ], " << ANIMAL_DEFAULT << std::endl;}

Animal		&Animal::operator=(const Animal &animal) { if (this == &animal) return (*this); _type = animal.getType(); return (*this);}

void		Animal::makeSound() const { std::cout << ANIMAL_PRINT << "\t : " << "type:[ " << _type << " ]," << " make : [ " << ANIMAL_SOUND  << " ] " << std::endl;}
std::string	Animal::getType() const { return (_type);}