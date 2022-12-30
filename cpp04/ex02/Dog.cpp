/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:22:10 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/24 18:29:14 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "(Dog) Defualt constructor is called." << std::endl;
	this->_type = "dog";
	this->_brain = new Brain();
}

Dog::Dog(Dog &src)
{
	std::cout << "(Dog) Copy constructor is called." << std::endl;
	this->_type = src._type;
	this->_brain = new Brain();
	*this->_brain = *src._brain;
}

Dog::~Dog(void)
{
	std::cout << "(Dog) Destructor is called." << std::endl;
	delete this->_brain;
}

Dog	&Dog::operator=(Dog &rhs)
{
	std::cout << "(Dog) Copy operator is called." << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		*this->_brain = *rhs._brain;
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woolff Woolf OoooooooooooooooWhoo!! << (DogSound)" << std::endl;
}

Brain	*Dog::getBrain(void)
{
	return (this->_brain);
}

std::ostream &operator<<(std::ostream &out, Dog &rhs)
{
	out << "(Dog) _type: " << rhs.getType();
	return (out);
}