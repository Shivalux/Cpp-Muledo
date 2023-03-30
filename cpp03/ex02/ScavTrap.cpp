/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:01:39 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/31 14:54:31 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "(ScavTrap) Defualt constructor is called." << std::endl;
	this->_name = "NO_NAME";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "(ScavTrap) Construtor is called." << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap &src)
{
	std::cout << "(ScavTrap) Copy constructor is called." << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "(ScavTrap) Destructorr is called." << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap &rhs)
{
	std::cout << "(ScavTrap) Copy assignment is called." << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

void	ScavTrap::attack(const std::string &taget)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap[" << this->_name << "] has no enough energy points for attacking!" << std::endl;
		return;
	}
	std::cout << "ScavTrap[" << this->_name << "] attacks " << taget << ", causing "
		<< this->_attackDamage << " point of damage!" << std::endl;
	this->_energyPoints -= 1;
}

void	ScavTrap::guandGate(void)
{
	std::cout << "ScavTrap: " << this->_name << " now is in Gate keeper mode." << std::endl;
}

std::ostream	&operator<<(std::ostream &out, ScavTrap &rhs)
{
	out << "(ScavTrap) name: ";
	rhs.printAttibute(1);
	out << ", hitPoints: ";
	rhs.printAttibute(2);
	out << ", energyPoints: ";
	rhs.printAttibute(3);
	out << ", attackDamage: ";
	rhs.printAttibute(4);
	out << ".";
	return (out);
}