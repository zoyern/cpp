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

#include "Harl.hpp"

Harl::~Harl() {}
Harl::Harl() {}
void	Harl::debug() { std::string levels[] = LEVELS; std::string msg[] = MSG;
			std::cout << "[ " << levels[0] << " ]" << std::endl << msg[0] << std::endl;
}
void	Harl::info() { std::string levels[] = LEVELS; std::string msg[] = MSG;
			std::cout << "[ " << levels[1] << " ]" << std::endl << msg[1] << std::endl;
}
void	Harl::warning() { std::string levels[] = LEVELS; std::string msg[] = MSG;
			std::cout << "[ " << levels[2] << " ]" << std::endl << msg[2] << std::endl;
}
void	Harl::error() { std::string levels[] = LEVELS; std::string msg[] = MSG;
			std::cout << "[ " << levels[3] << " ]" << std::endl << msg[3] << std::endl;
}
void Harl::complain(std::string level) { std::string levels[] = LEVELS;
	void	(Harl::*functions[SIZE])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < SIZE; i++)
        if (levels[i] == level) return ((this->*functions[i])(), (void)(std::cout << std::endl));
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}