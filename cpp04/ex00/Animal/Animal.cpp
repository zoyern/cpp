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

Animal::~Animal() { std::cout << ANIMAL_PRINT << "\t\t : " << "type:[ " << _type << " ], " << ANIMAL_DESTROY << std::endl;}
Animal::Animal() : _type(ANIMAL_TYPE) { std::cout << ANIMAL_PRINT << "\t\t : " << "type:[ " << _type << " ], " << ANIMAL_DEFAULT << std::endl;}
Animal::Animal(std::string type) : _type(type) { std::cout << ANIMAL_PRINT << "\t\t : " << "type:[ " << _type << " ], " << ANIMAL_DEFAULT << std::endl;;}
Animal::Animal(const Animal &cpy) { *this = cpy;}

Animal	&Animal::operator=(const Animal &cpy) { if (this == &cpy) return (*this); 
	_type = cpy._type;
	return (*this);
}

void		Animal::makeSound() const { std::cout << ANIMAL_PRINT << "\t\t : " << "type:[ " << _type << " ]," << " make : [ " << ANIMAL_SOUND  << " ] " << std::endl;}
std::string	Animal::getType() const { return (_type);}