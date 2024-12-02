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


#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <cmath>
# include "Fixed.hpp"

class Point {
	private:
		const Fixed	_x;
		const Fixed	_y;
	public:
		~Point();
		Point();
		Point(const Point &point);
		Point(const float x, const float y);
		Point	&operator=(const Point &point);

		Fixed	getX() const;
		Fixed	getY() const;
};

#endif