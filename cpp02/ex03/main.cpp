/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:19:25 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/14 22:15:00 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool	PointInTriangle (Point pt, Point v1, Point v2, Point v3);
bool	bsp(Point const a,  Point const b, Point const c, Point point);

int main(void)
{
	Point const	point1(4, 2), point2(0, 0), point3(1, 3);
	Point const	a(-1, -1);
	Point const	b(7, -1);
	Point const	c(4, 3);

	std::cout << "point1" << point1 << " (inside)  = " << bsp(a, b, c, point1) << std::endl;
	std::cout << "point2" << point2 << " (on-edge) = " << bsp(a ,b ,c, point2) << std::endl;
	std::cout << "point3" << point3 << " (outside) = " << bsp(a, b, c, point3) << std::endl;
	return (0);
}