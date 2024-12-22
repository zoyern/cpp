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


#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# ifndef FRAGTRAP
#  define FRAGTRAP_HEALTH 100
#  define FRAGTRAP_ENERGY 100
#  define FRAGTRAP_DAMAGE 30
#  define FRAGTRAP_COST 1
#  define FRAGTRAP_PRINT "FragTrap"
#  define FRAGTRAP_ATTACK "points of joy !"
#  define FRAGTRAP_HIGHTFIVES "points of joy !"
# endif

class FragTrap : public ClapTrap{
	public:
		virtual	~FragTrap();
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &cpy);

		FragTrap	&operator=(const FragTrap &cpy);

		void		highFivesGuys(void);
};

#endif