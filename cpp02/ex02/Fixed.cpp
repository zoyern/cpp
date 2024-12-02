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

Fixed::~Fixed() {}
Fixed::Fixed() : _value(0) {}
Fixed::Fixed(const Fixed &fixed) {*this = fixed;}
Fixed::Fixed(const int value) : _value(value << _bits) {}
Fixed::Fixed(const float value) : _value(roundf(value * (1 << _bits))) {}

Fixed			&Fixed::operator=(const Fixed &fixed) { if (this == &fixed) return (*this); setRawBits(fixed.getRawBits()); return (*this);}
Fixed			Fixed::operator++() { setRawBits(getRawBits() + 1); return (*this);}
Fixed			Fixed::operator--() {  setRawBits(getRawBits() - 1); return (*this);}
Fixed			Fixed::operator++(int) {  Fixed tmp = *this; setRawBits(getRawBits() + 1); return (tmp);}
Fixed			Fixed::operator--(int) {  Fixed tmp = *this; setRawBits(getRawBits() - 1); return (tmp);}
bool			Fixed::operator<(const Fixed &fixed) const { return (toFloat() < fixed.toFloat());}
bool			Fixed::operator>(const Fixed &fixed) const { return (toFloat() > fixed.toFloat());}
bool			Fixed::operator<=(const Fixed &fixed) const { return (toFloat() <= fixed.toFloat());}
bool			Fixed::operator>=(const Fixed &fixed) const { return (toFloat() >= fixed.toFloat());}
bool			Fixed::operator!=(const Fixed &fixed) const { return (toFloat() != fixed.toFloat());}
bool			Fixed::operator==(const Fixed &fixed) const { return (toFloat() == fixed.toFloat());}
float			Fixed::operator+(const Fixed &fixed) const { return (toFloat() + fixed.toFloat());}
float			Fixed::operator-(const Fixed &fixed) const { return (toFloat() - fixed.toFloat());}
float			Fixed::operator*(const Fixed &fixed) const { return (toFloat() * fixed.toFloat());}
float			Fixed::operator/(const Fixed &fixed) const { return (toFloat() / fixed.toFloat());}

int				Fixed::getRawBits() const { return (_value);}
void			Fixed::setRawBits(int const raw) { _value = raw;}
float			Fixed::toFloat(void) const {return ((float)this->_value / (float)(1 << this->_bits));}
int				Fixed::toInt(void) const {return (this->_value >> this->_bits);}

Fixed const		&Fixed::min(const Fixed &n1, const Fixed &n2) {return (n1 < n2 ? n1 : n2);}
Fixed const		&Fixed::max(const Fixed &n1, const Fixed &n2) {return (n1 > n2 ? n1 : n2);}

std::ostream&	operator<<(std::ostream &out, const Fixed& fixed) { return (out << fixed.toFloat());}