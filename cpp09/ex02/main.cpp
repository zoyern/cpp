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

#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#include <vector>
#include <deque>
#include <iomanip>



int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    try {
        
        // Tri avec vector et mesure du temps
        clock_t vectorStart = clock();
        std::vector<int> vectorResult = PmergeMe::sortVector<int>(argc - 1, argv + 1);
        clock_t vectorEnd = clock();
        double vectorTime = static_cast<double>(vectorEnd - vectorStart) * 1e6 / CLOCKS_PER_SEC;
        
        // Tri avec deque et mesure du temps
        clock_t dequeStart = clock();
        std::deque<int> dequeResult = PmergeMe::sortDeque<int>(argc - 1, argv + 1);
        clock_t dequeEnd = clock();
       	double dequeTime  = static_cast<double>(dequeEnd - dequeStart) * 1e6 / CLOCKS_PER_SEC;
        
		// Affichage Before
        std::cout << "Before:\t";
        for (int i = 1; i < argc; ++i) {
            std::cout << argv[i];
            if (i < argc - 1) std::cout << " ";
        }
        std::cout << std::endl;
        // Affichage After (utilise vectorResult)
        std::cout << "After:\t";
        for (size_t i = 0; i < vectorResult.size(); ++i) {
            std::cout << vectorResult[i];
            if (i < vectorResult.size() - 1) std::cout << " ";
        }
        std::cout << std::endl;
        
        // Affichage des temps avec format requis
        std::cout << std::fixed << std::setprecision(5);
        std::cout << "Time to process a range of " << (argc - 1) 
                  << " elements with std::vector : " << vectorTime << " us" << std::endl;
        std::cout << "Time to process a range of " << (argc - 1) 
                  << " elements with std::deque  : " << dequeTime << " us" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    return 0;
}