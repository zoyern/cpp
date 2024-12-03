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

# ifndef CAT
#  define CAT_PRINT "Cat"
#  define CAT_TYPE "Cat"
#  define CAT_SOUND "Miaou Miaou !"
#  define CAT_DEFAULT "created !"
#  define CAT_DESTROY "killed !"
# endif

class Cat : public Animal{
	public:
		~Cat();
		Cat();

		void	makeSound() const;
};

#endif