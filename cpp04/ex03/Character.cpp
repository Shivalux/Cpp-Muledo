/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:02:23 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/31 14:54:31 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("NO-NAME")
{
	// std::cout << "(Charactor) Defualt constructor is called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->_slot[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	// std::cout << "(Character) Constructor is called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->_slot[i] = NULL;
}

Character::Character(Character &src)
{
	// std::cout << "(Character) Copy constructor is called." << std::endl;
	this->_name = src._name;
	for (int i = 0; i < 4; i++)
	{
		if (src._slot[i] != NULL)
			this->_slot[i] = src._slot[i]->clone();
	}
}

Character::~Character(void)
{
	// std::cout << "(Character) Destructorr is called." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] != NULL)
			delete this->_slot[i];
	}
}

Character	&Character::operator=(Character &rhs)
{
	std::cout << "(Character) Copy assignment is called." << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++)
		{
			if (rhs._slot[i] != NULL)
				this->_slot[i] = rhs._slot[i]->clone();
		}
	}
	return (*this);
}

std::string const	&Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] == NULL)
		{
			std::cout << "(Character) [ " << this->_name << " ] success added [ "
				<< m->getType() << " ] into slot [ " << i + 1 << " ]" << std::endl;
			this->_slot[i] = m;
			return ;
		}
	}
	std::cout << "(Character) inventory[ " << this->_name << " ] is full, cannot add more Material." << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_slot[idx] != NULL)
	{
		std::cout << "(Character) [ " << this->_name << " ] success unequip [ "
			<< this->_slot[idx]->getType() << " ] from slot [ " << idx + 1 << " ]" << std::endl;
		this->_slot[idx] = NULL;
	}
	else
		std::cout << "(Character) [ " << this->_name << " ] cannot unequip Materia!!" << std::endl;
}

void	Character::use(int idx, ICharacter &taget)
{
	if (idx >= 0 && idx < 4 && this->_slot[idx] != NULL)
	{
		this->_slot[idx]->use(taget);
		return ;
	}
	else
		std::cout << "(Character) [ " << this->_name << " ] cannot use Materia!!" << std::endl;
}

AMateria **Character::getSlot(void)
{
	return (this->_slot);
}

std::ostream &operator<<(std::ostream &out, Character &rhs)
{
	out << "(Character) name[ " << rhs.getName() << " ], ";
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