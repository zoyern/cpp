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

int main()
{
	// on stack

	std::cout << "On stack (destroy when func exit) :" << std::endl << std::endl;
	randomChump("JOE");
	randomChump("MICHELLE");
	randomChump("KARINE");
	randomChump("BORIS");

	// on heap
	std::cout << std::endl << "On heap (destroy when use delete() ) :" << std::endl << std::endl;

	Zombie	*joe = newZombie("JOE");
	Zombie	*michelle = newZombie("MICHELLE");
	Zombie	*karine = newZombie("KARINE");
	Zombie	*boris = newZombie("BORIS");

	boris->announce();
	joe->announce();
	karine->announce();
	michelle->announce();

	delete(joe);
	delete(michelle);
	boris->announce();
	delete(boris);
	delete(karine);

	return 0;
}
