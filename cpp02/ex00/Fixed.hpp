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

#ifndef CONFIG
#  define BITS 8
#  define PRINT_DESTROY "Destructor called"
#  define PRINT_DEFAULT "Default constructor called"
#  define PRINT_COPY "Copy constructor called"
#  define PRINT_ASSIGNEMENT "Copy assignment operator called"
#  define PRINT_GET "getRawBits member function called"
#endif

class Fixed {
	private:
		int					_value;
		static const int	_bits;
	public:
		~Fixed();
		Fixed();
		Fixed(const Fixed &fixed);

		Fixed	&operator=(const Fixed &fixed);

		int		getRawBits() const;
		void	setRawBits(int const raw);
};

#endif