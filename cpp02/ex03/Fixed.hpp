/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:37:36 by marvin            #+#    #+#             */
/*   Updated: 2024/11/22 16:37:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

#ifndef CONFIG
#  define BITS 8
#endif

class Fixed {
	private:
		int					_value;
		static const int	_bits;
	public:
		~Fixed();
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int value);
		Fixed(const float value);

		Fixed	&operator=(const Fixed &fixed);
		Fixed	operator++();
		Fixed	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
		bool	operator<(const Fixed &fixed) const;
		bool	operator>(const Fixed &fixed) const;
		bool	operator<=(const Fixed &fixed) const;
		bool	operator>=(const Fixed &fixed) const;
		bool	operator!=(const Fixed &fixed) const;
		bool	operator==(const Fixed &fixed) const;
		float	operator+(const Fixed &fixed) const;
		float	operator-(const Fixed &fixed) const;
		float	operator*(const Fixed &fixed) const;
		float	operator/(const Fixed &fixed) const;

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

		static Fixed		&min(Fixed &n1, Fixed &n2);
		static const Fixed	&min(const Fixed &n1, const Fixed &n2);
		static Fixed		&max(Fixed &n1, Fixed &n2);
		static const Fixed	&max(const Fixed &n1, const Fixed &n2);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif