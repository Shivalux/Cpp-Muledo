/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:22:10 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/31 14:54:31 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "(Dog) Defualt constructor is called." << std::endl;
	this->_type = "dog";
}

Dog::Dog(Dog &src)
{
	std::cout << "(Dog) Copy constructor is called." << std::endl;
	this->_type = src._type;
}

Dog::~Dog(void)
{
	std::cout << "(Dog) Destructorr is called." << std::endl;
}

Dog	&Dog::operator=(Dog &rhs)
{
	std::cout << "(Dog) Copy operator is called." << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woolff Woolf OoooooooooooooooWhoo!! << (DogSound)" << std::endl;
}

std::ostream &operator<<(std::ostream &out, Dog &rhs)
{
	out << "(Dog) _type: " << rhs.getType();
	return (out);
}