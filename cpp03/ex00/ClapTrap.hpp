/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:37:36 by marvin            #+#    #+#             */
/*   Updated: 2024/11/22 16:37:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# ifndef CONFIG
#  define HEALTH 10
#  define ENERGY 10
#  define COST 1
#  define ATTACK 0
#  define PRINT "ClapTrap "
#  define PRINT_ATTACK " points of damage !"
#  define PRINT_ENERGY_FAIL "noting... (low energy or already dead !)"
#  define PRINT_HEAL " points of health!"
#  define PRINT_HEALTH " new health : "
#  define PRINT_FAIL "noting... (already dead !)"
#  define PRINT_DESTROY " destroyed !"
#  define PRINT_DEFAULT " constructor called !"
# endif

class ClapTrap {
	private:
		std::string	_name;
		int			_health;
		int			_energy;
		int			_damage;
	public:
		~ClapTrap();
		ClapTrap();
		ClapTrap(std::string name);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif