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


#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

# ifndef MATERIASOURCE
#  define MATERIASOURCE_INVENTORY 4
# endif

class MateriaSource : virtual public IMateriaSource {
	private:
		AMateria	*_inventory[MATERIASOURCE_INVENTORY];
	public:
		~MateriaSource();
		MateriaSource();
		void		learnMateria(AMateria *materia);
		AMateria	*createMateria(std::string const &type);
};

#endif