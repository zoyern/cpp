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

Cat::~Cat() { std::cout << CAT_PRINT << "\t\t : " << "type:[ " << _type << " ], " << CAT_DESTROY << std::endl;}
Cat::Cat() : Animal(CAT_TYPE) { std::cout << CAT_PRINT << "\t\t : " << "type:[ " << _type << " ], " << CAT_DEFAULT << std::endl;}
Cat::Cat(const Cat &cpy) : Animal(cpy) { std::cout << CAT_PRINT << "\t\t : " << "type:[ " << _type << " ], cpy" << CAT_DEFAULT << std::endl;}

Cat		&Cat::operator=(const Cat &cpy) { if (this == &cpy) return (*this); Animal::operator=(cpy); return (*this);}

void	Cat::makeSound() const { std::cout << CAT_PRINT << "\t\t : " << "type:[ " << _type << " ]," << " make : [ " << CAT_SOUND  << " ] " << std::endl;}