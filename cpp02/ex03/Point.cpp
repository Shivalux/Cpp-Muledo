/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:29:00 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/31 14:54:31 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) 
{
	// std::cout << "(Point) Defualt construtor is called" << std::endl;
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
	// std::cout << "(Point) Construtor is called" << std::endl;
}

Point::Point(Point const &src) : _x(src._x), _y(src._y)
{
	// std::cout << "(Point) Copy construtor is called" << std::endl;
}

Point::~Point(void)
{
	// std::cout << "(Point) Destructorr is called" << std::endl;
}

Fixed	Point::getXPoint(void) const
{
	return (this->_x);
}

Fixed	Point::getYPoint(void) const
{
	return (this->_y);
}

Point	&Point::operator=(Point const &rhs)
{
	(void)rhs;
	return (*this);
}

std::ostream	&operator<<(std::ostream  &out, Point const &rhs)
{
	out << "(" << rhs.getXPoint() << ", " << rhs.getYPoint() << ")";
	return (out);
}