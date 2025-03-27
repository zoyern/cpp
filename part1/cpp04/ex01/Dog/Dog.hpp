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


#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "../Animal/Animal.hpp"
# include "../Brain/Brain.hpp"

# ifndef DOG
#  define DOG_PRINT "Dog"
#  define DOG_TYPE "Dog"
#  define DOG_SOUND "Woaf Woaf !"
#  define DOG_DEFAULT "created !"
#  define DOG_COPY "copy !"
#  define DOG_DESTROY "killed !"
# endif

class Dog : public Animal{
	private:
		Brain	*_brain;
	public:
		~Dog();
		Dog();
		Dog(const Dog &dog);

		Dog		&operator=(const Dog &dog);

		void	makeSound() const;
		Brain	*getBrain() const;
		Brain	*getBrain();
};

#endif