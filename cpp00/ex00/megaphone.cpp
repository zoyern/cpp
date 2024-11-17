/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:06:56 by almounib          #+#    #+#             */
/*   Updated: 2024/11/17 17:29:19 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (!(ac - 1))
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 0);
	for (int i = 1; i < ac; i++)
		for (int j = 0; av[i][j]; j++) std::cout << (char)std::toupper(av[i][j]);
	std::cout << std::endl;
	return (0);
}