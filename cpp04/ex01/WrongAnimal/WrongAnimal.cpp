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

#include "WrongAnimal.hpp"

WrongAnimal::~WrongAnimal() { std::cout << WRONGANIMAL_PRINT << " :\t" << "type:[ " << _type << " ], " << WRONGANIMAL_DESTROY << std::endl;}
WrongAnimal::WrongAnimal() : _type(WRONGANIMAL_TYPE) { std::cout << WRONGANIMAL_PRINT << " :\t" << "type:[ " << _type << " ], " << WRONGANIMAL_DEFAULT << std::endl;}
WrongAnimal::WrongAnimal(std::string type) : _type(type) { std::cout << WRONGANIMAL_PRINT << " :\t" << "type:[ " << _type << " ], " << WRONGANIMAL_DEFAULT << std::endl;;}

void		WrongAnimal::makeSound() const { std::cout << WRONGANIMAL_PRINT << " :\t" << "type:[ " << _type << " ]," << " make : [ " << WRONGANIMAL_SOUND  << " ] " << std::endl;}
std::string	WrongAnimal::getType() const { return (_type);}