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

template<typename Container>
void print(const std::string& label, const Container& data) {
    std::cout << label;
    for (size_t i = 0; i < data.size() && i < 5; ++i) 
        std::cout << (i ? " " : "") << data[i];
    if (data.size() > 5) std::cout << " [...]";
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    if (argc < 2) return std::cerr << "Error" << std::endl, 1;
    
    try {
        // OPTIMAL SYNTAX: Container type explicit in template parameters
        clock_t start1 = clock();
        std::vector<int> vectorResult = PmergeMe<int, std::vector<int> >::sort(argv + 1, argv + argc);
        double timeVector = (clock() - start1) * 1e6 / CLOCKS_PER_SEC;
        
        clock_t start2 = clock();
        std::deque<int> dequeResult = PmergeMe<int, std::deque<int> >::sort(argv + 1, argv + argc);
        double timeDeque = (clock() - start2) * 1e6 / CLOCKS_PER_SEC;
        
        print("Before: ", std::vector<std::string>(argv + 1, argv + argc));
        print("After: ", vectorResult);
        
        std::cout.precision(5); std::cout << std::fixed;
        std::cout << "Time to process a range of " << argc-1 << " elements with std::vector : " << timeVector << " us\n";
        std::cout << "Time to process a range of " << argc-1 << " elements with std::deque : " << timeDeque << " us\n";
        
    } catch(...) { return std::cerr << "Error" << std::endl, 1; }
    return 0;
}