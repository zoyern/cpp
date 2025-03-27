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


#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "../Animal/Animal.hpp"
# include "../Brain/Brain.hpp"

# ifndef CAT
#  define CAT_PRINT "Cat"
#  define CAT_TYPE "Cat"
#  define CAT_SOUND "Miaou Miaou !"
#  define CAT_DEFAULT "created !"
#  define CAT_COPY "copy !"
#  define CAT_DESTROY "killed !"
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