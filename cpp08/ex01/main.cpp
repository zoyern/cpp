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
#include <ctime>

int main() {
    try {
        Span sp(10);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);

        std::vector<int> bloc;
        bloc.push_back(9);
        bloc.push_back(11);
        bloc.push_back(1);
        bloc.push_back(20);
        sp.addNumbers(bloc.begin(), bloc.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << '\n';
        std::cout << "Longest span: " << sp.longestSpan() << '\n';

        std::list<int> trop;
        trop.push_back(30);
        trop.push_back(40);
        trop.push_back(50);
        trop.push_back(60);
        sp.addNumbers(trop.begin(), trop.end());

    } catch (const std::exception &e) {
        std::cerr << "Erreur: " << e.what() << '\n';
    }

    try {
        Span sp2(3);
        sp2.addNumber(42);
        std::cout << sp2.shortestSpan() << '\n';
    } catch (const std::exception &e) {
        std::cerr << "Erreur: " << e.what() << '\n';
    }

    try {
        Span sp3(3);
        sp3.addNumber(42);
        std::cout << sp3.longestSpan() << '\n';
    } catch (const std::exception &e) {
        std::cerr << "Erreur: " << e.what() << '\n';
    }

	try {
        Span sp(15000);
        srand(time(0));
        for (int i = 0; i < 10000; i++) {
            sp.addNumber(rand() % 1000000);
        }
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        
        std::vector<int> big_data;
        for (int i = 0; i < 5000; i++) {
            big_data.push_back(i * 100);
        }
        sp.addNumbers(big_data.begin(), big_data.end());
        
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}