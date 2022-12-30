/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:21:36 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/24 18:29:14 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "(WrongCat) Defualt constructor is called." << std::endl;
	this->_type = "Wrongcat";
}

WrongCat::WrongCat(WrongCat &src)
{
	std::cout << "(WrongCat) Copy constructor is called." << std::endl;
	this->_type = src._type;
}

WrongCat::~WrongCat(void)
{
	std::cout << "(WrongCat) Destructor is called." << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat &rhs)
{
	std::cout << "(WrongCat) Copy operator is called." << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}
void	WrongCat::makeSound(void) const
{
	std::cout << "Wrrraooo.. Maaorrao!! << (WrongcatSound)" << std::endl;
}

std::ostream &operator<<(std::ostream &out, WrongCat &rhs)
{
	out << "(WrongCat) _type: " << rhs.getType();
	return (out);
}