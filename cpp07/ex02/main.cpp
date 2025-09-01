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


#include "Array.hpp"
#include <iostream>
#include <string>

#define TEST_SIZE 5

template <typename T>
void printArray(const Array<T>& arr) {
    for (unsigned int i = 0; i < arr.size(); ++i)
        std::cout << "[" << i << "] = " << arr[i] << "\n";
}

int main() {
    std::cout << "==== [1] Empty array test ====\n";
    Array<int> empty;
    std::cout << "Size: " << empty.size() << "\n";
    try { (void)empty[0]; }
    catch (std::exception& e) {
        std::cout << "Exception caught (empty): " << e.what() << "\n";
    }

    std::cout << "\n==== [2] Int array ====\n";
    Array<int> intArray(TEST_SIZE);
    for (unsigned int i = 0; i < TEST_SIZE; ++i) intArray[i] = i * 10;
    printArray(intArray);

    std::cout << "\n==== [3] Copy constructor ====\n";
    Array<int> copyArray(intArray);
    printArray(copyArray);
    std::cout << "Modifying original...\n";
    intArray[0] = 999;
    std::cout << "Original: " << intArray[0] << ", Copy: " << copyArray[0] << "\n";
    printArray(copyArray);
    std::cout << "---original----\n";
    printArray(intArray);

    std::cout << "\n==== [4] Assignment operator ====\n";
    Array<int> assignArray;
    assignArray = intArray;
    printArray(assignArray);
    std::cout << "Modifying assigned...\n";
    assignArray[1] = 888;
    std::cout << "Assign: " << assignArray[1] << ", Original: " << intArray[1] << "\n";
    printArray(assignArray);

    std::cout << "\n==== [5] Out of bounds ====\n";
    try { std::cout << intArray[TEST_SIZE] << "\n"; }
    catch (std::exception& e) {
        std::cout << "Exception caught (OOB): " << e.what() << "\n";
    }

    std::cout << "\n==== [6] String array ====\n";
    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "world";
    strArray[2] = "!";
    printArray(strArray);

    std::cout << "\n==== [7] Double array with default values ====\n";
    Array<double> dblArray(3);
    printArray(dblArray);

    std::cout << "\n==== All tests passed if no crash ====\n";
    return 0;
}