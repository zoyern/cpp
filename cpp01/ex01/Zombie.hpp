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
# include <cstdlib>

# ifndef HORDE
#  define HORDE 5
#  define HORDE_NAME "Unamed Zombie Horde"
# endif

# ifndef PRINT
#  define PRINT ": BraiiiiiiinnnzzzZ..."
#  define PRINT_DIE ": MORT !"
# endif

class Zombie {
	private:
		std::string	_name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		std::string	get();
		void		set(std::string name);
		void	announce();
};

Zombie*	zombieHorde(int N, std::string name);

#endif