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


#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

# ifndef ANIMAL
#  define ANIMAL_PRINT "Animal"
#  define ANIMAL_TYPE "Animal"
#  define ANIMAL_SOUND "Undefined noises !"
#  define ANIMAL_DEFAULT "created !"
#  define ANIMAL_DESTROY "killed !"
# endif

class Animal {
	protected:
		std::string	_type;
	public:
		virtual ~Animal();
		Animal();
		Animal(std::string type);
		Animal(const Animal &cpy);

		Animal	&operator=(const Animal &cpy);

		std::string		getType() const;
		virtual void	makeSound() const;
};

#endif