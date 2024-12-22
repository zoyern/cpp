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

#include "Cat.hpp"

Cat::~Cat() { delete _brain; std::cout << CAT_PRINT << "\t : " << "type:[ " << _type << " ], " << CAT_DESTROY << std::endl;}
Cat::Cat() : Animal(CAT_TYPE), _brain(new Brain()) { std::cout << CAT_PRINT << "\t : " << "type:[ " << _type << " ], " << CAT_DEFAULT << std::endl;}
Cat::Cat(const Cat &cat) : Animal(cat._type), _brain(new Brain(*cat._brain)) { std::cout << CAT_PRINT << "\t : " << CAT_COPY << std::endl; *this = cat;}

Cat		&Cat::operator=(const Cat &cat) { if (this == &cat) return (*this); *_brain = *cat._brain; return (*this);}

void	Cat::makeSound() const { std::cout << CAT_PRINT << "\t : " << "type:[ " << _type << " ]," << " make : [ " << CAT_SOUND  << " ] " << std::endl;}
Brain	*Cat::getBrain() const { return (_brain);}
Brain	*Cat::getBrain() { return (_brain);}