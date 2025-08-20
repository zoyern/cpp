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


int main() {
	std::vector<int> v;
	v.push_back(7);
	v.push_back(6);
	v.push_back(42);

    std::list<int> l;
	l.push_back(4);
	l.push_back(2);
	l.push_back(0);

    try { std::cout << "vector hit: " << *easyfind(v, 42) << "\n"; }
    catch (std::exception& e) { std::cout << e.what() << "\n"; }

    try { std::cout << "list hit: " << *easyfind(l, 42) << "\n"; }
    catch (std::exception& e) { std::cout << e.what() << "\n"; }
    return 0;
}