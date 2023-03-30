/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:53:24 by sharnvon          #+#    #+#             */
/*   Updated: 2023/03/27 15:56:43 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("NO-TYPE")
{
	std::cout << "(AAnimal) Defualt constructor is called." << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "(AAnimal) Constructor is called." << std::endl;
}

AAnimal::AAnimal(AAnimal &src)
{
	std::cout << "(AAnimal) Copy constructor is called." << std::endl;
	this->_type = src._type;
}

AAnimal::~AAnimal(void)
{
	std::cout << "(AAnimal) Destructor is called." << std::endl;
}

AAnimal	&AAnimal::operator=(AAnimal &rhs)
{
	std::cout << "(AAnimal) Copy operator is called." << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

std::string const	AAnimal::getType(void) const
{
	return (this->_type);
}

std::ostream &operator<<(std::ostream &out, AAnimal &rhs)
{
	out << "(AAnimal) _type: " << rhs.getType();
	return (out);
}