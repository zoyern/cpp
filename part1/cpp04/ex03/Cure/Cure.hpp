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


#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "../AMateria/AMateria.hpp"
# include "../Character/ICharacter.hpp"

# ifndef CURE
#  define CURE_PRINT "Cure"
#  define CURE_TYPE "cure"
#  define CURE_ATTACK "* heals"
#  define CURE_END "’s wounds *"
# endif

class Cure : virtual public AMateria{
	public:
		~Cure();
		Cure();
		Cure(const Cure &cpy);

		Cure		&operator=(const Cure &cpy);

		void		use(ICharacter &character);
		AMateria	*clone() const;
};

#endif