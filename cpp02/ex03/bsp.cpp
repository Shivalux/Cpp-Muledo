/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:11:34 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/14 22:15:41 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

float sign(Point point, Point a, Point b)
{
	float	aX = a.getXPoint().toFloat();
	float	aY = a.getYPoint().toFloat();
	float	bX = b.getXPoint().toFloat();
	float	bY = b.getYPoint().toFloat();
	float	pointX = point.getXPoint().toFloat();
	float	pointY = point.getYPoint().toFloat();

	return (((pointX - bX) * (aY - bY)) - ((aX - bX) * (pointY - bY)));
}

bool bsp(Point const a, Point const b, Point const c, Point point)
{
	bool	has_neg, has_pos;
	float	position1;
	float	position2;
	float	position3;

	position1 = sign(point, a, b);
	position2 = sign(point, b, c);
	position3 = sign(point, c, a);
	has_neg = (position1 < 0) || (position2 < 0) || (position3 < 0);
	has_pos = (position1 > 0) || (position2 > 0) || (position3 > 0);
	return !(has_neg && has_pos);
}
