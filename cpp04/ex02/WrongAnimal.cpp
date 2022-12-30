/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:53:24 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/24 18:29:14 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("NO-TYPE")
{
	std::cout << "(WrongAnimal) Defualt constructor is called." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &src)
{
	std::cout << "(WrongAnimal) Copy constructor is called." << std::endl;
	this->_type = src._type;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "(WrongAnimal) Destructor is called." << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal &rhs)
{
	std::cout << "(WrongAnimal) Copy operator is called." << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "....................... << (noSound)" << std::endl;
}

std::string const	WrongAnimal::getType(void) const
{
	return (this->_type);
}

std::ostream &operator<<(std::ostream &out, WrongAnimal &rhs)
{
	out << "(WrongAnimal) _type: " << rhs.getType();
	return (out);
}