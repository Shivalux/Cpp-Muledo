/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:53:24 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/31 14:54:31 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("NO-TYPE")
{
	std::cout << "(Animal) Defualt constructor is called." << std::endl;
}

Animal::Animal(Animal &src)
{
	std::cout << "(Animal) Copy constructor is called." << std::endl;
	this->_type = src._type;
}

Animal::~Animal(void)
{
	std::cout << "(Animal) Destructorr is called." << std::endl;
}

Animal	&Animal::operator=(Animal &rhs)
{
	std::cout << "(Animal) Copy operator is called." << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}
void	Animal::makeSound(void) const
{
	std::cout << "....................... << (noSound)" << std::endl;
}

std::string const	Animal::getType(void) const
{
	return (this->_type);
}

std::ostream &operator<<(std::ostream &out, Animal &rhs)
{
	out << "(Animal) _type: " << rhs.getType();
	return (out);
}