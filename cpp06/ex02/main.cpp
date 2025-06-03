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

#include "Base.hpp"
#include "class/A.hpp"
#include "class/B.hpp"
#include "class/C.hpp"
#include <stdlib.h>

Base	*generate(void) {
	std::cout << "Creating ";
	switch (rand() % 3) {
		case 0: std::cout << "A" << std::endl; return (new A());
		case 1: std::cout << "B" << std::endl; return (new B());
		case 2: std::cout << "C" << std::endl; return (new C());
	}
	return (0);
}

void identify(Base* p) {
	std::cout << "ptr identify: ";
    if (dynamic_cast<A*>(p)) std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p)) std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) std::cout << "C" << std::endl;
	else std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
    try { (void)dynamic_cast<A&>(p); std::cout << "A" << std::endl; return; }
    catch (...) {}
    try { (void)dynamic_cast<B&>(p); std::cout << "B" << std::endl; return; }
    catch (...) {}
    try { (void)dynamic_cast<C&>(p); std::cout << "C" << std::endl; return; }
    catch (...) {}
}


int main(void) {
	for (int k = 0; k < 10; k++) {
		Base *p = generate();

		identify(p);

		identify(*p);

		delete (p);

		std::cout << "\n";
	}
}