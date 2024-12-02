/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:36:29 by marvin            #+#    #+#             */
/*   Updated: 2024/11/22 16:36:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(const Point a, const Point b, const Point c, const Point point);

void	print_bsp(const Point a, const Point b, const Point c, const Point point)
{
	std::cout << "bsp : [ " << point.getX() << ", " << point.getY() << " ] : " << (bsp(a, b, c, point) ? "\033[32mTRUE\033[0m" : "\033[31mFALSE\033[0m") << std::endl
	 << "\t[ " << a.getX() << ", " << a.getY() << " ]" << std::endl
	 << "[ " << b.getX() << ", " << b.getY() << " ]\t"
	 << "[ " << c.getX() << ", " << c.getY() << " ]" << std::endl;
	std::cout << "---------------------------------------------------------------------\n" << std::endl;
}

int main(void)
{
	print_bsp(Point(), Point(10, 0), Point(0, 10), Point(1, 1));
	print_bsp(Point(0, 0), Point(10, 0), Point(0, 10), Point(-1, -1));
	print_bsp(Point(0, 0), Point(10, 0), Point(0, 10), Point(-1, 5));
	print_bsp(Point(0, -50), Point(50, 30), Point(-50, 30), Point(0, 20));
	return (0);
}