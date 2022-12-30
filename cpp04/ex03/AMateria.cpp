/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:11:06 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/24 18:29:14 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("NO-TYPE")
{
	// std::cout << "(AMateria) Defualt consturctor is called." << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	// std::cout << "(AMateria) Constructor is called." << std::endl;
}

AMateria::AMateria(AMateria &src)
{
	// std::cout << "(AMateria) Copy constructor is called." << std::endl;
	this->_type = src._type;
}

AMateria::~AMateria(void)
{
	// std::cout << "(AMateria) Deconstructor is called." << std::endl;
}

AMateria	&AMateria::operator=(AMateria &rhs)
{
	// std::cout << "(AMateria) Copy assignment is called." << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

std::string const	&AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::setType(std::string type)
{
	this->_type = type;
}

void	AMateria::use(ICharacter &taget)
{
	(void)taget;
	std::cout << "(AMateria) without user can do nothing!!!" << std::endl;
}