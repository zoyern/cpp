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


#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

# ifndef DIAMONDTRAP
#  define DIAMONDTRAP_PRINT "DiamondTrap"
# endif

class DiamondTrap : public ScavTrap, public FragTrap{
	private:
		std::string	_name;
	public:
		~DiamondTrap();
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &cpy);

		DiamondTrap	&operator=(const DiamondTrap &cpy);

		virtual void    attack(const std::string &target);
		void whoAmI();
};

#endif