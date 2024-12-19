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


#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# ifndef SCAVTRAP
#  define SCAVTRAP_HEALTH 100
#  define SCAVTRAP_ENERGY 50
#  define SCAVTRAP_DAMAGE 20
#  define SCAVTRAP_COST 1
#  define SCAVTRAP_PRINT "ScavTrap"
#  define SCAVTRAP_ATTACK "points of presence !"
# endif

class ScavTrap : virtual public ClapTrap{
	private:
		bool	_guardGate;
	public:
		~ScavTrap();
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &cpy);

		ScavTrap	&operator=(const ScavTrap &cpy);

		virtual void    attack(const std::string &target);
		void			guardGate();
};

#endif