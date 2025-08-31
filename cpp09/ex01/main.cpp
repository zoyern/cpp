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

#include "RPN.hpp"
#include <list>

int main(int ac, char **av) {
	if (ac != 2) { return (std::cerr << "Error" << std::endl, 1); }

    try	{ std::cout << RPN::out(av[1]) << std::endl;}
	catch(const std::exception& e) { std::cerr << e.what() << std::endl;}
	
	return (0);
}
