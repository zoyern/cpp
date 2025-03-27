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

void testMateriaSource() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    AMateria* tmp;
    tmp = src->createMateria("ice");
    std::cout << "Created Ice Materia: " << (tmp ? "Success" : "Failed") << std::endl;
    delete tmp;

    tmp = src->createMateria("cure");
    std::cout << "Created Cure Materia: " << (tmp ? "Success" : "Failed") << std::endl;
    delete tmp;

    tmp = src->createMateria("fire"); // Should fail
    std::cout << "Created Fire Materia: " << (tmp ? "Success" : "Failed") << std::endl;

    delete src;
}

void testCharacter() {
    ICharacter* me = new Character("me");
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();

    me->equip(ice);
    me->equip(cure);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob); // Should use Ice
    me->use(1, *bob); // Should use Cure

    me->unequip(0);
    me->use(0, *bob); // Should fail, slot 0 is empty

    delete bob;
    delete me;
}

void testDeepCopy() {
    Character original("original");
    AMateria* ice = new Ice();
    original.equip(ice);

    Character copy(original);
    std::cout << "Original Name: " << original.getName() << std::endl;
    std::cout << "Copy Name: " << copy.getName() << std::endl;

    copy.use(0, original); // Should use Ice

    Character assigned("assigned");
    assigned = original;
    std::cout << "Assigned Name: " << assigned.getName() << std::endl;

    assigned.use(0, original); // Should use Ice
}

void testMemoryLeaks() {
    Character* characters[10];
    for (int i = 0; i < 10; ++i) {
        characters[i] = new Character("character" + i);
        characters[i]->equip(new Ice());
        characters[i]->equip(new Cure());
    }

    for (int i = 0; i < 10; ++i) {
        delete characters[i];
    }
}

int main() {
    std::cout << "--- Test MateriaSource ---" << std::endl;
    testMateriaSource();

    std::cout << "\n--- Test Character ---" << std::endl;
    testCharacter();

    std::cout << "\n--- Test Deep Copy ---" << std::endl;
    testDeepCopy();

    std::cout << "\n--- Test Memory Leaks ---" << std::endl;
    testMemoryLeaks();

    return 0;
}
