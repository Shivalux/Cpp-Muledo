/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 00:40:38 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/24 18:29:14 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("\"NO_NAME\""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "(ClapTrap) Defualt constructor is called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "(ClapTrap) Consturctor is called." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &src) : _name(src._name), _hitPoints(src._hitPoints),
	_energyPoints(src._energyPoints), _attackDamage(src._attackDamage)
{
	std::cout << "(ClapTrap) Copy constructor is called." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "(ClapTrap) Destructor is called." << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << "(ClapTrap) Copy assignment operator." << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

void	ClapTrap::printAttibute(int mode) const
{
	if (mode == 1)
		std::cout << this->_name;
	else if (mode == 2)
		std::cout << this->_hitPoints;
	else if (mode == 3)
		std::cout << this->_energyPoints;
	else if (mode == 4)
		std::cout << this->_attackDamage;
}

void	ClapTrap::attack(const std::string &taget)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap[" << this->_name << "] has no enough energy points for attacking!" << std::endl;
		return;
	}
	std::cout << "ClapTrap[" << this->_name << "] attacks " << taget << ", causing "
		<< this->_attackDamage << " point of damage!" << std::endl;
	this->_energyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->_name << " has taken damage " << amount << " points, decreased its hitpoint from "
		<< this->_hitPoints;
	if (this->_hitPoints - amount < 0)
		this->_hitPoints = 0;
	this->_hitPoints -= amount;
	std::cout << " to " << this->_hitPoints << "." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " has no enough energy points for being repaired." << std::endl;
		return ;
	}
	std::cout << this->_name << " is repaired itself " << amount <<" points, its hit points increased from " << this->_hitPoints
		 << " to " << this->_hitPoints + amount << "." << std::endl;
	this->_energyPoints -= 1;
	this->_hitPoints += amount;
}

std::ostream	&operator<<(std::ostream &out, ClapTrap &rhs)
{
	out << "(ClapTrap) name: ";
	rhs.printAttibute(1);
	out << ", hitPoints: ";
	rhs.printAttibute(2);
	out << ", energyPoint: ";
	rhs.printAttibute(3);
	out << ", attackDamage: ";
	rhs.printAttibute(4);
	out << ".";
	return (out);

}