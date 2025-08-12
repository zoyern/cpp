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

#include "Span.hpp"
#include <list>

int main() {
    try {
        Span sp(10);

        // Ajout un par un
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);

        // Ajout via un vecteur (range d'itérateurs)
        std::vector<int> bloc;
        bloc.push_back(9);
        bloc.push_back(11);
        bloc.push_back(1);
        bloc.push_back(20);
        sp.addNumbers(bloc.begin(), bloc.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << '\n';
        std::cout << "Longest span: " << sp.longestSpan() << '\n';

        // Test dépassement
        std::list<int> trop;
        trop.push_back(30);
        trop.push_back(40);
        trop.push_back(50);
        trop.push_back(60);
        sp.addNumbers(trop.begin(), trop.end()); // devrait déclencher une exception

    } catch (const std::exception &e) {
        std::cerr << "Erreur: " << e.what() << '\n';
    }

    try {
        // Test avec moins de 2 éléments
        Span sp2(3);
        sp2.addNumber(42);
        std::cout << sp2.shortestSpan() << '\n'; // devrait déclencher une exception
    } catch (const std::exception &e) {
        std::cerr << "Erreur: " << e.what() << '\n';
    }

    try {
        // Test avec moins de 2 éléments
        Span sp3(3);
        sp3.addNumber(42);
        std::cout << sp3.longestSpan() << '\n'; // devrait déclencher une exception
    } catch (const std::exception &e) {
        std::cerr << "Erreur: " << e.what() << '\n';
    }

    return 0;
}