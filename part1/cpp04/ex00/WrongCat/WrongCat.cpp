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

#include "WrongCat.hpp"

WrongCat::~WrongCat() { std::cout << WRONGCAT_PRINT << "\t : " << "type:[ " << _type << " ], " << WRONGCAT_DESTROY << std::endl;}
WrongCat::WrongCat() : Animal(WRONGCAT_TYPE), WrongAnimal(WRONGCAT_TYPE) { std::cout << WRONGCAT_PRINT << "\t : " << "type:[ " << _type << " ], " << WRONGCAT_DEFAULT << std::endl;}
WrongCat::WrongCat(const WrongCat &cpy) : Animal(cpy), WrongAnimal(cpy) {
    std::cout << WRONGCAT_PRINT << "\t : " << "type:[ " << _type << " ], cpy" << WRONGCAT_DEFAULT << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &cpy) { if (this == &cpy) return (*this); WrongAnimal::operator=(cpy); return (*this);}

void		WrongCat::makeSound() const { std::cout << WRONGCAT_PRINT << "\t : " << "type:[ " << _type << " ]," << " make : [ " << WRONGCAT_SOUND  << " ] " << std::endl;}