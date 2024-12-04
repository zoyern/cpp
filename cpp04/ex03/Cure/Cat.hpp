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

# ifndef CURE
#  define CURE_PRINT "Cure"
#  define CURE_ATTACK "* heals"
#  define CURE_END "’s wounds *"
# endif

class Cat : public Animal{
	private:
		Brain	*_brain;
	public:
		~Cat();
		Cat();
		Cat(const Cat &cat);

		Cat		&operator=(const Cat &cat);

		void	makeSound() const;
		Brain	*getBrain() const;
		Brain	*getBrain();
};

#endif