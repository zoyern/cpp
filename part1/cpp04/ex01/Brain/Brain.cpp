/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:37:34 by marvin            #+#    #+#             */
/*   Updated: 2024/11/22 16:37:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//for (size_t i = 0; i < BRAIN_IDEAS; i++) _ideas[i] = "";

Brain::~Brain() { std::cout << BRAIN_PRINT << "\t : " << BRAIN_DESTROY << std::endl;}
Brain::Brain() { std::cout << BRAIN_PRINT << "\t : " << BRAIN_DEFAULT << std::endl;}
Brain::Brain(const Brain &cpy) { std::cout << BRAIN_PRINT << "\t : " << BRAIN_COPY << std::endl; *this = cpy;}

Brain		&Brain::operator=(const Brain &cpy) { if (this == &cpy) return (*this); for (size_t i = 0; i < BRAIN_IDEAS; i++) _ideas[i] = cpy._ideas[i]; return (*this);}

std::string	Brain::getIdea(size_t index) const { if (index >= BRAIN_IDEAS) return (NULL); return (_ideas[index]);}
bool		Brain::setIdea(std::string idea)  { for (size_t i = 0; i < BRAIN_IDEAS; i++) if (_ideas[i] == "") return (_ideas[i] = idea, true); return (false);}