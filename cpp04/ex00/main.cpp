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

#include "Dog/Dog.hpp"
#include "Cat/Cat.hpp"
#include "WrongCat/WrongCat.hpp"


int main(void) {
  // Test de création et destruction
  std::cout << "--- Test de création et destruction ---" << std::endl;
  {
	  Animal* animal = new Animal();
	  Animal* cat = new Cat();
	  Animal* dog = new Dog();
	  WrongAnimal* wrongAnimal = new WrongAnimal();
	  WrongCat* wrongCat = new WrongCat();

	  delete animal;
	  delete cat;
	  delete dog;
	  delete wrongAnimal;
	  delete wrongCat;
  }

  // Test de polymorphisme
  std::cout << "\n--- Test de polymorphisme ---" << std::endl;
  {
	  Animal* animal = new Animal();
	  Animal* cat = new Cat();
	  Animal* dog = new Dog();
	  WrongAnimal* wrongAnimal = new WrongAnimal();
	  WrongCat* wrongCat = new WrongCat();

	  animal->makeSound(); // Devrait appeler Animal::makeSound
	  cat->makeSound();    // Devrait appeler Cat::makeSound
	  dog->makeSound();    // Devrait appeler Dog::makeSound
	  wrongAnimal->makeSound(); // Devrait appeler WrongAnimal::makeSound
	  wrongCat->makeSound();    // Devrait appeler WrongCat::makeSound

	  delete animal;
	  delete cat;
	  delete dog;
	  delete wrongAnimal;
	  delete wrongCat;
  }

  // Test de copie et d'affectation
  std::cout << "\n--- Test de copie et d'affectation ---" << std::endl;
  {
	  Cat originalCat;
	  Cat copiedCat(originalCat);
	  Cat assignedCat = originalCat;

	  std::cout << "Original Cat Type: " << originalCat.getType() << std::endl;
	  std::cout << "Copied Cat Type: " << copiedCat.getType() << std::endl;
	  std::cout << "Assigned Cat Type: " << assignedCat.getType() << std::endl;

	  Dog originalDog;
	  Dog copiedDog(originalDog);
	  Dog assignedDog = originalDog;

	  std::cout << "Original Dog Type: " << originalDog.getType() << std::endl;
	  std::cout << "Copied Dog Type: " << copiedDog.getType() << std::endl;
	  std::cout << "Assigned Dog Type: " << assignedDog.getType() << std::endl;

	  WrongCat originalWrongCat;
	  WrongCat copiedWrongCat(originalWrongCat);
	  WrongCat assignedWrongCat = originalWrongCat;

	  std::cout << "Original WrongCat Type: " << originalWrongCat.getType() << std::endl;
	  std::cout << "Copied WrongCat Type: " << copiedWrongCat.getType() << std::endl;
	  std::cout << "Assigned WrongCat Type: " << assignedWrongCat.getType() << std::endl;
  }

  // Test de type
  std::cout << "\n--- Test de type ---" << std::endl;
  {
	  Animal animal;
	  Cat cat;
	  Dog dog;
	  WrongAnimal wrongAnimal;
	  WrongCat wrongCat;

	  std::cout << "Animal Type: " << animal.getType() << std::endl;
	  std::cout << "Cat Type: " << cat.getType() << std::endl;
	  std::cout << "Dog Type: " << dog.getType() << std::endl;
	  std::cout << "WrongAnimal Type: " << wrongAnimal.getType() << std::endl;
	  std::cout << "WrongCat Type: " << wrongCat.getType() << std::endl;
  }
  return 0;
}