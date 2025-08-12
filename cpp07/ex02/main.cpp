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

#include "Array.tpp"

#define TEST_SIZE 5

template <typename T>
void printArray(Array<T>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << "[" << i << "] = " << arr[i] << std::endl;
    }
}

int main() {
    std::cout << "==== [1] Empty array test ====" << std::endl;
    Array<int> empty;
    std::cout << "Size: " << empty.size() << std::endl;
    try { empty[0]; }
    catch (std::exception& e) {
        std::cout << "Exception caught (empty): " << e.what() << std::endl;
    }

    std::cout << "\n==== [2] Int array ====" << std::endl;
    Array<int> intArray(TEST_SIZE);
    for (unsigned int i = 0; i < TEST_SIZE; ++i) intArray[i] = i * 10;
    printArray(intArray);

    std::cout << "\n==== [3] Copy constructor ====" << std::endl;
    Array<int> copyArray(intArray);
    printArray(copyArray);

    std::cout << "Modifying original..." << std::endl;
    intArray[0] = 999;
    std::cout << "Original: " << intArray[0] << ", Copy: " << copyArray[0] << std::endl;
    printArray(copyArray);
    std::cout << "---original----" << std::endl;
    printArray(intArray);
    std::cout << "\n==== [4] Assignment operator ====" << std::endl;
    Array<int> assignArray;
    assignArray = intArray;
    printArray(assignArray);
    std::cout << "Modifying assigned..." << std::endl;
    assignArray[1] = 888;
    std::cout << "Assign: " << assignArray[1] << ", Original: " << intArray[1] << std::endl;
    printArray(assignArray);

    std::cout << "\n==== [5] Out of bounds ====" << std::endl;
    try { std::cout << intArray[TEST_SIZE] << std::endl; }
    catch (std::exception& e) {
        std::cout << "Exception caught (OOB): " << e.what() << std::endl;
    }

    std::cout << "\n==== [6] String array ====" << std::endl;
    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "world";
    strArray[2] = "!";
    printArray(strArray);

    std::cout << "\n==== [7] Double array with default values ====" << std::endl;
    Array<double> dblArray(3);
    printArray(dblArray); // should show 0 or garbage if not initialized properly

    std::cout << "\n==== All tests passed if no crash ====" << std::endl;

    return 0;
}