/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:54:43 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/24 18:29:14 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource(void)
{
	// std::cout << "(MateriaSource) Defualt constructor is called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->_slot[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource &src)
{
	// std::cout << "(MateriaSource) Copy constructor is called." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src._slot[i] != NULL)
			this->_slot[i] = src._slot[i]->clone();
	}
}

MateriaSource::~MateriaSource(void)
{
	// std::cout << "(MateriaSource) Deconstructor is called." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] != NULL)
			delete this->_slot[i];
	}
}

MateriaSource	&MateriaSource::operator=(MateriaSource &rhs)
{
	// std::cout << "(MateriaSource) Copy assignment is called." << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (rhs._slot[i] != NULL)
				this->_slot[i] = rhs._slot[i]->clone();
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] == NULL)
		{
			this->_slot[i] = m;//m->clone();
			std::cout << "(MateriaSource) success learned " << "[ " << m->getType()
				<< " ] into slot number[ " << i + 1 << " ]" << std::endl;
			return ;
		}
	}
	std::cout << "(MateriaSource) inventory is full, unsuccess learned" << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] != NULL && this->_slot[i]->getType() == type)
		{
			std::cout << "(MateriaSource) sucess created [ " << this->_slot[i]->getType()
				<< " ] from slot number [ " << i + 1 << " ]" << std::endl;
			return (this->_slot[i]->clone());
		}
	}
	std::cout << "(MateriaSource) unsucess created, don't found [ "
		<< type << " ] in the inventory" << std::endl;
	return (NULL);
}

AMateria	**MateriaSource::getSlot(void)
{
	return (this->_slot);
}

std::ostream	&operator<<(std::ostream &out, MateriaSource &rhs)
{
	out << "(Matiria) ";
	for (int i = 0; i < 4; i++)
	{
			out << "slot[" << i + 1 << "]" << "[ ";
			if (rhs.getSlot()[i] != NULL)
				out << rhs.getSlot()[i]->getType() << " ][ "
					<< &rhs.getSlot()[i]->getType() << " ] ";
			else
				out << "NULL ] ";
	}
	return (out);
}