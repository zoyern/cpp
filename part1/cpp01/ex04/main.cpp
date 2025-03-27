/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:06:56 by almounib          #+#    #+#             */
/*   Updated: 2024/12/19 09:18:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	sed(std::string filename, std::string s1, std::string s2)
{
	std::ifstream src(filename.c_str());
	if (!src.is_open()) return (std::cerr << "Erreur : impossible d'ouvrir le fichier source." << std::endl, 1);
	if (s1.empty())
		return (src.close(), 1);
	std::ofstream dst((filename += ".replace").c_str(), std::ios::out | std::ios::trunc);
    if (!dst.is_open()) return (std::cerr << "Erreur : impossible d'ouvrir ou de créer le fichier destination." << std::endl, src.close(), 1);
	for (std::string line; std::getline(src, line); dst << line << std::endl) 
		for (size_t pos = 0; (pos = line.find(s1, pos)) != std::string::npos; pos += s2.length())
			line.erase(pos, s1.length()).insert(pos, s2);
	return (src.close(), dst.close(), 0);
}

int	main(int ac, char **av)
{
	if (ac > 3)
		return (sed(av[1], av[2], av[3]));
	return (std::cout << "need 3 args !"<<std::endl, 0);
}