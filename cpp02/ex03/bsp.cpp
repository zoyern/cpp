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

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
	Fixed c1 = (b.getX() - a.getX()) * (p.getY() - a.getY()) - (b.getY() - a.getY()) * (p.getX() - a.getX());
	Fixed c2 = (c.getX() - b.getX()) * (p.getY() - c.getY()) - (c.getY() - b.getY()) * (p.getX() - c.getX());
	Fixed c3 = (a.getX() - c.getX()) * (p.getY() - a.getY()) - (a.getY() - c.getY()) * (p.getX() - a.getX());

	return ((Fixed(0) < c1 && Fixed(0) < c2 && Fixed(0) < c3) || (c1 < Fixed(0) && c2 < Fixed(0) && c3 < Fixed(0)));
}