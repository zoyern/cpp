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


#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <cstdlib>

# ifndef VAR
#  define ATTACK " attacks with their "
#  define W_DEFAULT "hands"
# endif

class Weapon {
	private:
		std::string	_type;
	public:
		~Weapon();
		Weapon();
		Weapon(const std::string type);
		const std::string	&getType() const;
		void				setType(const std::string type);
};

#endif