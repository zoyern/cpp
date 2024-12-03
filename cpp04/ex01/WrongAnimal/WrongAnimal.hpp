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


#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

# ifndef WRONGANIMAL
#  define WRONGANIMAL_PRINT "WrongAnimal"
#  define WRONGANIMAL_TYPE "WrongAnimal"
#  define WRONGANIMAL_SOUND "Undefined wrong noises !"
#  define WRONGANIMAL_DEFAULT "created !"
#  define WRONGANIMAL_DESTROY "killed !"
# endif

class WrongAnimal {
	protected:
		std::string	_type;
	public:
		virtual ~WrongAnimal();
		WrongAnimal();
		WrongAnimal(std::string type);
		
		std::string		getType() const;
		virtual void	makeSound() const;
};

#endif