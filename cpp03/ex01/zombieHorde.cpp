/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:36:35 by marvin            #+#    #+#             */
/*   Updated: 2024/11/22 16:36:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) { if (N <= 0) return (NULL);
	Zombie *zombies = new Zombie[N];

	for (int i = 0; i < N; i++) zombies[i].set(name);
	return (zombies);
}

