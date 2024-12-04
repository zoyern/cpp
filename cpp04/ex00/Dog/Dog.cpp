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

Dog::~Dog() { std::cout << DOG_PRINT << "\t : " << "type:[ " << _type << " ], " << DOG_DESTROY << std::endl;}
Dog::Dog() : Animal(DOG_TYPE) { std::cout << DOG_PRINT << "\t : " << "type:[ " << _type << " ], " << DOG_DEFAULT << std::endl;}

void	Dog::makeSound() const { std::cout << DOG_PRINT << "\t : " << "type:[ " << _type << " ]," << " make : [ " << DOG_SOUND  << " ] " << std::endl;}