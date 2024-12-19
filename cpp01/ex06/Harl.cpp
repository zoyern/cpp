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
void	Harl::complain(std::string level) {
	int	lvl = getLevel(level) - 1;
	do {
		lvl++;
		switch (lvl){
			case 0:	debug(); break;
			case 1:	info(); break;
			case 2: warning(); break;
			case 3: error(); break;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		}
	} while (lvl < SIZE - 1 && lvl != -1);
}
int	Harl::getLevel(std::string level) { std::string levels[] = LEVELS;
	for (int i = 0; i < SIZE; i++)
        if (levels[i] == level) return (i);
	return (-1);
}