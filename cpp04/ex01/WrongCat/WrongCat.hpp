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


#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "../WrongAnimal/WrongAnimal.hpp"

# ifndef WRONGCAT
#  define WRONGCAT_PRINT "WrongCat"
#  define WRONGCAT_TYPE "WrongCat"
#  define WRONGCAT_SOUND "Meuuuuh Meeuuuh !"
#  define WRONGCAT_DEFAULT "created !"
#  define WRONGCAT_DESTROY "killed !"
# endif

class WrongCat : public WrongAnimal{
	public:
		~WrongCat();
		WrongCat();

		void	makeSound() const;
};

#endif