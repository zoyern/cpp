/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:36:29 by marvin            #+#    #+#             */
/*   Updated: 2024/11/22 16:36:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character/Character.hpp"
#include "MateriaSource/MateriaSource.hpp"
#include "Ice/Ice.hpp"
#include "Cure/Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria	*tmp;
	AMateria	*tmp1;
	AMateria	*tmp2;
	AMateria	*tmp3;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp1 = src->createMateria("cure");
	me->equip(tmp1);
	tmp = src->createMateria("fire");
	me->equip(tmp);
	std::cout << std::endl;
	std::cout << "USE ON A NEW CHARACTER:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(-4, *bob);
	me->use(18, *bob);
	Character	*charles = new Character("Charles");
	tmp2 = src->createMateria("cure");
	charles->equip(tmp2);
	tmp3 = src->createMateria("ice");
	charles->equip(tmp3);
	tmp = src->createMateria("earth");
	charles->equip(tmp);
	Character	*pomme = new Character("pomme");
	std::cout << std::endl;
	std::cout << "DEEP COPY VS SOURCE:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	charles->unequip(0);
	pomme->unequip(1);
	tmp = src->createMateria("cure");
	pomme->equip(tmp);
	tmp = src->createMateria("ice");
	pomme->equip(tmp);
	tmp = src->createMateria("ice");
	pomme->equip(tmp);
	tmp = src->createMateria("ice");
	pomme->equip(tmp);
	tmp = src->createMateria("ice");
	pomme->equip(tmp);
	tmp = src->createMateria("ice");
	pomme->equip(tmp);
	charles->use(0, *bob);
	charles->use(1, *bob);
	charles->use(2, *bob);
	charles->use(3, *bob);
	std::cout << "-----------------------" << std::endl;
	pomme->use(0, *charles);
	pomme->use(1, *charles);
	pomme->use(2, *charles);
	pomme->use(3, *charles);
	std::cout << std::endl;
	std::cout << "UNEQUIP:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	me->unequip(-1);
	me->unequip(18);
	me->unequip(3);
	me->use(1, *charles);
	me->unequip(1);
	me->use(1, *charles);

	delete bob;
	delete me;
	delete src;
	delete charles;
	delete pomme;
	std::cout << "-----------------------" << std::endl;
	return (0);
}