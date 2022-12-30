/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:23:38 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/14 22:23:32 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBit = 8;

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = value << _fractionalBit;
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	_value = (int)(roundf(value * (1 << _fractionalBit)));
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBit member function called" << std::endl;
	return(this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	float	result;
	
	result = (float)_value / (float)(1 << _fractionalBit);
	return (result);
}

int		Fixed::toInt(void) const
{
	return (_value >> _fractionalBit);
}

Fixed&	Fixed::operator=(Fixed const &rhs)
{
	if (this != &rhs)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		this->_value = rhs._value;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &c, Fixed const &rhs)
{
	c << rhs.toFloat();
	return (c);
}