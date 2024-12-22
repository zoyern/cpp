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


#ifndef CHARACTERE_HPP
# define CHARACTERE_HPP

# include <iostream>
# include "ICharacter.hpp"

# ifndef CHARACTERE
#  define CHARACTERE_INVENTORY 4
#  define CHARACTERE_ATTACK "* heals"
#  define CHARACTERE_END "’s wounds *"
# endif

class Character : virtual public ICharacter{
	private:
		std::string	_name;
		AMateria	*_inventory[CHARACTERE_INVENTORY];
		AMateria	**_trash;
		size_t		_trash_size;

		void		setTrash(AMateria *materia);
	protected:
		Character();
	public:
		~Character();
		Character(std::string name);
		Character(const Character &cpy);

		Character			&operator=(const Character &cpy);

		std::string const	&getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);

};

#endif