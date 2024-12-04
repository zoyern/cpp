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


int main(void) {
	std::cout << std::endl << "--- PDF: ---" << std::endl
            << std::endl;
  Dog *dog = new Dog();
  Cat *cat = new Cat();

  delete dog;
  delete cat;

  std::cout << std::endl << "--- Array of animals ---" << std::endl
            << std::endl;

  Animal *array_animals[10];
  for (int i = 0; i < 10; i++) {
    if (i % 2)
      array_animals[i] = new Dog();
    else
      array_animals[i] = new Cat();
  }
  std::cout << "------------" << std::endl;

  for (int i = 0; i < 10; i++) array_animals[i]->makeSound();

  std::cout << "------------" << std::endl;

  for (int i = 0; i < 10; i++) delete array_animals[i];

  std::cout << std::endl << "--- Test for deep copy ---" << std::endl
            << std::endl;
  Cat *cat2 = new Cat();
  cat2->getBrain().setIdea("Hmm... fish!");
  cat2->getBrain().setIdea("I wanna play...");
  for (size_t i = 0; i < BRAIN_IDEAS; i++)
  {
	std::string idea = cat2->getBrain().getIdea(i);
	if (idea == "")
		break;
	std::cout << "idea : " << i << " | " << idea << std::endl;
  }
	std::cout << "-------" << std::endl;

  std::cout << std::endl << "--- Making a deep copy ---" << std::endl
            << std::endl;

  Cat *cat3 = new Cat(*cat2);
  cat2->getBrain().setIdea("Gotta sleep now...");
  std::cout << std::endl;
  for (size_t i = 0; i < BRAIN_IDEAS; i++)
  {
	std::string idea = cat2->getBrain().getIdea(i);
	if (idea == "")
		break;
	std::cout << "idea : " << i << " | " << idea << std::endl;
  }
std::cout << "-------" << std::endl;
  std::cout << std::endl;
    for (size_t i = 0; i < BRAIN_IDEAS; i++)
  {
	std::string idea = cat3->getBrain().getIdea(i);
	if (idea == "")
		break;
	std::cout << "idea : " << i << " | " << idea << std::endl;
  }
	std::cout << "-------" << std::endl;
  std::cout << std::endl;

  std::cout << std::endl << "--- Copy assignment operator ---" << std::endl
            << std::endl;

	std::cout << "New Cat" << std::endl << std::endl;
  Cat *cat4 = new Cat();
	std::cout << std::endl <<"Assigning cat 3 to cat 4" << std::endl << std::endl;
  *cat4 = *cat3;
	std::cout << std::endl ;
    for (size_t i = 0; i < BRAIN_IDEAS; i++)
  {
	std::string idea = cat4->getBrain().getIdea(i);
	if (idea == "")
		break;
	std::cout << "idea : " << i << " | " << idea << std::endl;
  }
	std::cout << "-------" << std::endl;
  std::cout << std::endl;
  cat3->getBrain().setIdea("No sleeping now!!!");
    for (size_t i = 0; i < BRAIN_IDEAS; i++)
  {
	std::string idea = cat3->getBrain().getIdea(i);
	if (idea == "")
		break;
	std::cout << "idea : " << i << " | " << idea << std::endl;
  }
	std::cout << "-------" << std::endl;
  std::cout << std::endl;
    for (size_t i = 0; i < BRAIN_IDEAS; i++)
  {
	std::string idea = cat4->getBrain().getIdea(i);
	if (idea == "")
		break;
	std::cout << "idea : " << i << " | " << idea << std::endl;
  }
	std::cout << "-------" << std::endl;
  std::cout << std::endl;

	std::cout << std::endl << "--- Destruction ---" << std::endl
            << std::endl;

  delete cat2;
  delete cat3;
  delete cat4;
  return 0;
}