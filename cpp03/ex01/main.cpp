/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:36:29 by marvin            #+#    #+#             */
/*   Updated: 2024/11/22 16:36:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int ac, char **av)
{
	int	n;
	std::string	name;

	n = ac > 1 ? std::atoi(av[1]) : HORDE;
	name = ac > 2 ? av[2] : HORDE_NAME;
	Zombie	*zombies = zombieHorde(n, name);
	for (int i = 0; i < n; i++) zombies[i].announce();
	return (delete[] zombies, 0);
}
