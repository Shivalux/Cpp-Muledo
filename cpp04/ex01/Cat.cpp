/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:21:36 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/24 18:29:14 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "(Cat) Defualt constructor is called." << std::endl;
	this->_type = "cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat &src)
{
	std::cout << "(Cat) Copy constructor is called." << std::endl;
	this->_type = src._type;
	this->_brain = new Brain();
	*this->_brain = *src._brain;
}

Cat::~Cat(void)
{
	std::cout << "(Cat) Destructor is called." << std::endl;
	delete this->_brain;
}

Cat	&Cat::operator=(Cat &rhs)
{
	std::cout << "(Cat) Copy operator is called." << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		*this->_brain = *rhs._brain;
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Wrrraooo.. Maaorrao!! << (catSound)" << std::endl;
}

Brain	*Cat::getBrain(void)
{
	return (this->_brain);
}

std::ostream &operator<<(std::ostream &out, Cat &rhs)
{
	out << "(Cat) _type: " << rhs.getType();
	return (out);
}