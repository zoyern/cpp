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
Fixed::Fixed() : _value(0) {  std::cout << PRINT_DEFAULT << std::endl;}
Fixed::Fixed(const Fixed &fixed) {std::cout << PRINT_COPY << std::endl; *this = fixed;}
Fixed::Fixed(const int value): _value(value << _bits) { std::cout << PRINT_INT << std::endl;}
Fixed::Fixed(const float value) : _value(roundf(value * (1 << _bits))) { std::cout << PRINT_FLOAT << std::endl;}

Fixed	&Fixed::operator=(const Fixed &fixed) {
	if (this == &fixed) return (*this);
	setRawBits(fixed.getRawBits());
	std::cout << PRINT_ASSIGNEMENT << std::endl;
	return (*this);
}
std::ostream&	operator<<(std::ostream &out, const Fixed& fixed) { return (out << fixed.toFloat());}

int		Fixed::getRawBits() const { return (_value);}
void	Fixed::setRawBits(int const raw) { _value = raw;}
float	Fixed::toFloat(void) const {return ((float)_value / (float)(1 << _bits));}
int		Fixed::toInt(void) const {return (_value >> _bits);}
