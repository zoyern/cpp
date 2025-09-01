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

#include "iter.hpp"

void append42(std::string &s) {
    s += "42";
}

void multiplyByTwo(int &n) {
    n *= 2;
}

void setTrue(bool &b) {
    b = true;
}

int main() {
    std::cout << "--- Test avec int ---" << std::endl;
    int numbers[] = {1, 2, 3, 4};
    size_t nSize = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Avant : ";
    for (size_t i = 0; i < nSize; ++i) std::cout << numbers[i] << " ";
    std::cout << std::endl;

    iter(numbers, nSize, multiplyByTwo);

    std::cout << "Après : ";
    for (size_t i = 0; i < nSize; ++i) std::cout << numbers[i] << " ";
    std::cout << std::endl << std::endl;

    std::cout << "--- Test avec std::string ---" << std::endl;
    std::string words[] = {"hello", "world", "cpp"};
    size_t wSize = sizeof(words) / sizeof(words[0]);

    std::cout << "Avant : ";
    for (size_t i = 0; i < wSize; ++i) std::cout << words[i] << " ";
    std::cout << std::endl;

    iter(words, wSize, append42);

    std::cout << "Après : ";
    for (size_t i = 0; i < wSize; ++i) std::cout << words[i] << " ";
    std::cout << std::endl << std::endl;

    std::cout << "--- Test avec bool ---" << std::endl;
    bool flags[] = {false, false, false};
    size_t bSize = sizeof(flags) / sizeof(flags[0]);

    std::cout << "Avant : ";
    for (size_t i = 0; i < bSize; ++i) std::cout << flags[i] << " ";
    std::cout << std::endl;

    iter(flags, bSize, setTrue);

    std::cout << "Après : ";
    for (size_t i = 0; i < bSize; ++i) std::cout << flags[i] << " ";
    std::cout << std::endl;

    return 0;
}