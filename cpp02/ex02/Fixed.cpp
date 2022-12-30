/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:23:38 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/12 21:56:54 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBit = 8;

Fixed::Fixed(void) : _value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value)
{
	// std::cout << "Int constructor called" << std::endl;
	_value = value << _fractionalBit;
}

Fixed::Fixed(float const value)
{
	// std::cout << "Float constructor called" << std::endl;
	_value = (int)(roundf(value * (1 << _fractionalBit)));
}

Fixed::Fixed(Fixed const &src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBit member function called" << std::endl;
	return(this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
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
		// std::cout << "Copy assignment operator called" << std::endl;
		this->_value = rhs.getRawBits();
	}
	return (*this);
}

bool	Fixed::operator>(Fixed const &rhs)
{
	return (this->_value > rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const &rhs)
{
	return (this->_value >= rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const &rhs)
{
	return (this->_value < rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const &rhs)
{
	return (this->_value <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const &rhs)
{
	return (this->_value == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const &rhs)
{
	return (this->_value != rhs.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &rhs)
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &rhs)
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &rhs)
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &rhs)
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed	Fixed::operator++(void)
{
	this->_value = _value + 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	operator++();
	return (tmp);
}

Fixed	Fixed::operator--(void)
{
	this->_value = _value - 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	operator--();
	return (tmp);
}

Fixed	&Fixed::max(Fixed &fixedNum1, Fixed &fixedNum2)
{
	if (fixedNum1.toFloat() > fixedNum2.toFloat())
		return (fixedNum1);
	else if (fixedNum1.toFloat() < fixedNum2.toFloat())
		return (fixedNum2);
	else
		return (fixedNum1);
}

Fixed	&Fixed::max(Fixed const &fixedNum1, Fixed const &fixedNum2)
{
	if (fixedNum1.toFloat() > fixedNum2.toFloat())
		return ((Fixed &)fixedNum1);
	else if (fixedNum1.toFloat() < fixedNum2.toFloat())
		return ((Fixed &)fixedNum2);
	else
		return ((Fixed &)fixedNum1);
}

Fixed	&Fixed::min(Fixed &fixedNum1, Fixed &fixedNum2)
{
	if (fixedNum1.toFloat() < fixedNum2.toFloat())
		return (fixedNum1);
	else if (fixedNum1.toFloat() > fixedNum2.toFloat())
		return (fixedNum2);
	else
		return (fixedNum1);
}

Fixed	&Fixed::min(Fixed const &fixedNum1, Fixed const &fixedNum2)
{
	if (fixedNum1.toFloat() < fixedNum2.toFloat())
		return ((Fixed &)fixedNum1);
	else if (fixedNum1.toFloat() > fixedNum2.toFloat())
		return ((Fixed &)fixedNum2);
	else
		return ((Fixed &)fixedNum1);
}

std::ostream	&operator<<(std::ostream &c, Fixed const &rhs)
{
	c << rhs.toFloat();
	return (c);
}