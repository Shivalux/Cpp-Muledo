/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:32:54 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/14 22:14:48 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class Point
{
	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const &src);
		~Point(void);
		Point	&operator=(Point const &rhs);
		Fixed	getXPoint(void) const;
		Fixed	getYPoint(void) const;

	private:
		Fixed const	_x;
		Fixed const	_y;
};

std::ostream	&operator<<(std::ostream  &out, Point const &rhs);

#endif