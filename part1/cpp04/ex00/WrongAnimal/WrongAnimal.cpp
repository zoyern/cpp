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

WrongAnimal::~WrongAnimal() { std::cout << WRONGANIMAL_PRINT << "\t : " << "type:[ " << _type << " ], " << WRONGANIMAL_DESTROY << std::endl;}
WrongAnimal::WrongAnimal() : Animal(WRONGANIMAL_TYPE) { std::cout << WRONGANIMAL_PRINT << "\t : " << "type:[ " << _type << " ], " << WRONGANIMAL_DEFAULT << std::endl;}
WrongAnimal::WrongAnimal(std::string type) : Animal(type) { std::cout << WRONGANIMAL_PRINT << "\t : " << "type:[ " << _type << " ], " << WRONGANIMAL_DEFAULT << std::endl;;}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy) : Animal(cpy) { std::cout << WRONGANIMAL_PRINT << "\t : " << "type:[ " << _type << " ], cpy " << WRONGANIMAL_DEFAULT << std::endl;}

WrongAnimal		&WrongAnimal::operator=(const WrongAnimal &cpy) { if (this == &cpy) return (*this); Animal::operator=(cpy); return (*this);}

void			WrongAnimal::makeSound() const { std::cout << WRONGANIMAL_PRINT << "\t : " << "type:[ " << _type << " ]," << " make : [ " << WRONGANIMAL_SOUND  << " ] " << std::endl;}