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

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

# ifndef PRINT
	#  define PRINT_DESTROY "destroyed !"
	#  define PRINT_DEFAULT "constructor called !"
	#  define PRINT_FAIL "noting... (low energy or already dead !)"
	#  define PRINT_HEAL "points of health!"
	#  define PRINT_NEWHEAL "new health :"
	#  define PRINT_DEATH "noting... (already dead !)"
# endif

# ifndef CLAPTRAP
#  define CLAPTRAP_HEALTH 10
#  define CLAPTRAP_ENERGY 10
#  define CLAPTRAP_DAMAGE 0
#  define CLAPTRAP_COST 1
#  define CLAPTRAP_PRINT "ClapTrap"
#  define CLAPTRAP_ATTACK "points of damage !"
# endif

class ClapTrap {
	protected:
		std::string	_name;
		int			_health;
		int			_energy;
		int			_damage;
	public:
		~ClapTrap();
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &cpy);

		ClapTrap	&operator=(const ClapTrap &cpy);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif