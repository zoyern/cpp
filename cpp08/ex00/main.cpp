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
#include "easyfind.hpp"


int main() {
	std::vector<int> v;
	v.push_back(7);
	v.push_back(6);
	v.push_back(42);

    std::list<int> l;
	l.push_back(6);
	l.push_back(2);
	l.push_back(0);;

    try { std::vector<int>::iterator vit = easyfind(v, 42); std::cout << "vector = ( " << *vit << " find at index : " << vit - v.begin() << " )"<< std::endl; }
    catch (std::exception& e) { std::cout << "vector = " << e.what() << std::endl; }

    try { std::list<int>::iterator lit = easyfind(l, 42); std::cout << "list = ( " << *lit << " find at index : " << std::distance(l.begin(), lit) << " )"<< std::endl; }
    catch (std::exception& e) { std::cout << "list = " << e.what() << std::endl; }
    return (0);
}