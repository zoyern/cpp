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

#include <vector>
#include <list>
#include "easyfind.tpp"

#define FSUCCES "Valeur trouvée : "
#define FINVALID "Valeur non trouvée !"


int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);

    std::cout << "Test avec std::vector<int> :" << std::endl;
    std::vector<int>::iterator itVec = easyfind(vec, 20);
    itVec != vec.end() ? std::cout << FSUCCES << *itVec << std::endl : std::cout << FINVALID << std::endl;

    std::cout << "\nTest avec std::list<int> :" << std::endl;
    std::list<int>::iterator itList = easyfind(lst, 42);
    itList != lst.end() ? std::cout << FSUCCES << *itList << std::endl : std::cout << FINVALID << std::endl;


    return 0;
}