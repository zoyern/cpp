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

#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &cpy) {*this = cpy;}
ScalarConverter::ScalarConverter() {}

ScalarConverter			&ScalarConverter::operator=(const ScalarConverter &cpy){ if (this == &cpy) return (*this); return (*this);}

static void		ScalarConverter::convert(std::string s){(void)s;
	

}
