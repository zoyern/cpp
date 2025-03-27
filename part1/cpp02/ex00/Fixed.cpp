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

#include "Fixed.hpp"

const int Fixed::_bits = BITS;

Fixed::~Fixed() { std::cout << PRINT_DESTROY << std::endl;}
Fixed::Fixed() : _value(0) { std::cout << PRINT_DEFAULT << std::endl;}
Fixed::Fixed(const Fixed &fixed) {std::cout << PRINT_COPY << std::endl; *this = fixed;}

Fixed	&Fixed::operator=(const Fixed &fixed) {
	if (this == &fixed) return (*this);
	std::cout << PRINT_ASSIGNEMENT << std::endl;
	setRawBits(fixed.getRawBits());
	return (*this);
}

int		Fixed::getRawBits() const { std::cout << PRINT_GET << std::endl; return (_value);}
void	Fixed::setRawBits(int const raw) { _value = raw;}
