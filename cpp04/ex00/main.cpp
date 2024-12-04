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
  std::cout << "--- Project pdf: derived class overrides base class method ---"
            << std::endl
            << std::endl;
  const Animal *meta = new Animal();
  const Animal *i = new Cat();
  const Animal *j = new Dog();
  std::cout << i->getType() << " " << std::endl;
  std::cout << j->getType() << " " << std::endl;
  i->makeSound(); 
  j->makeSound();
  meta->makeSound();
  delete meta;
  delete i;
  delete j;

  std::cout << std::endl << "--- Objects are created as derived class ---"
            << std::endl
            << std::endl;
  const Animal *meta2 = new Animal();
  const Cat *i2 = new Cat();
  const Dog *j2 = new Dog();
  std::cout << i2->getType() << " " << std::endl;
  std::cout << j2->getType() << " " << std::endl;
  i2->makeSound();
  j2->makeSound();
  meta2->makeSound();
  delete meta2;
  delete i2;
  delete j2;

  std::cout << std::endl << "--- WrongAnimal Test: derived class doesn't override base "
               "class function ---"
            << std::endl
            << std::endl;
  const WrongAnimal *meta3 = new WrongAnimal();
  std::cout << "-------" << std::endl;
  const WrongAnimal *i3 = new WrongCat();
  std::cout << meta3->getType() << " " << std::endl;
  std::cout << i3->getType() << " " << std::endl;
  meta3->makeSound();
  i3->makeSound(); 
  delete meta3;
  delete i3;

  return 0;
}