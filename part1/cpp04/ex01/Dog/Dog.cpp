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

#include "Dog.hpp"

Dog::~Dog() { delete _brain; std::cout << DOG_PRINT << "\t : " << "type:[ " << _type << " ], " << DOG_DESTROY << std::endl;}
Dog::Dog() : Animal(DOG_TYPE), _brain(new Brain()) { std::cout << DOG_PRINT << "\t : " << "type:[ " << _type << " ], " << DOG_DEFAULT << std::endl;}
Dog::Dog(const Dog &dog) : Animal(dog._type), _brain(new Brain(*dog._brain)) { std::cout << DOG_PRINT << "\t : " << DOG_COPY << std::endl; *this = dog;}

Dog		&Dog::operator=(const Dog &dog) { if (this == &dog) return (*this); _brain = dog._brain; return (*this);}

void	Dog::makeSound() const { std::cout << DOG_PRINT << "\t : " << "type:[ " << _type << " ]," << " make : [ " << DOG_SOUND  << " ] " << std::endl;}
Brain	*Dog::getBrain() const { return (_brain);}
Brain	*Dog::getBrain() { return (_brain);}