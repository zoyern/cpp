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

WrongCat::~WrongCat() { std::cout << WRONGCAT_PRINT << " :\t" << "type:[ " << _type << " ], " << WRONGCAT_DESTROY << std::endl;}
WrongCat::WrongCat() : WrongAnimal(WRONGCAT_TYPE) { std::cout << WRONGCAT_PRINT << " :\t" << "type:[ " << _type << " ], " << WRONGCAT_DEFAULT << std::endl;}

void	WrongCat::makeSound() const { std::cout << WRONGCAT_PRINT << " :\t" << "type:[ " << _type << " ]," << " make : [ " << WRONGCAT_SOUND  << " ] " << std::endl;}