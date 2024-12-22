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


#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "../AMateria/AMateria.hpp"
# include "../Character/ICharacter.hpp"

# ifndef ICE
#  define ICE_PRINT "Ice"
#  define ICE_TYPE "ice"
#  define ICE_ATTACK "* shoots an ice bolt at "
#  define ICE_END " *"
# endif

class Ice : virtual public AMateria{
	public:
		~Ice();
		Ice();
		Ice(const Ice &cpy);

		Ice			&operator=(const Ice &cpy);

		void		use(ICharacter &character);
		AMateria	*clone() const;
};

#endif