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

#include "Point.hpp"

Point::~Point() {}
Point::Point() : _x(0), _y(0) {}
Point::Point(const Point &point) : _x(point.getX()), _y(point.getY()) {}
Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point	&Point::operator=(const Point &point) { return (this == &point ? *this : *this);}
Fixed	Point::getX() const { return (_x);}
Fixed	Point::getY() const { return (_y);}