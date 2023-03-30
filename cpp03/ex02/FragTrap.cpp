/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:52:05 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/31 14:54:31 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "(FragTrap) Defualt constrctor is called." << std::endl;
	this->_name = "NO_NAME";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "(FragTrap) Constructor is called." << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap &src)
{
	std::cout << "(FragTrap) Copy Constructor is called." << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
}

FragTrap::~FragTrap(void)
{
	std::cout << "(FragTrap) Destructorr is called." << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap &rhs)
{
	std::cout << "(FragTrap) Copy assignment is called." << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

void	FragTrap::attack(const std::string &taget)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "FragTrap[" << this->_name << "] has no enough energy points for attacking!" << std::endl;
		return;
	}
	std::cout << "FragTrap[" << this->_name << "] attacks " << taget << ", causing "
		<< this->_attackDamage << " point of damage!" << std::endl;
	this->_energyPoints -= 1;
}

void	FragTrap::highFiveGuy(void)
{
	std::cout << "FragTrap: " << this->_name << " requset a positive hight-five." << std::endl;
}

std::ostream	&operator<<(std::ostream &out, FragTrap &rhs)
{
	out << "(FragTrap) name: ";
	rhs.printAttibute(1);
	out << ", hitPoinst: ";
	rhs.printAttibute(2);
	out << ", energyPoints: ";
	rhs.printAttibute(3);
	out << ", attactDamage: ";
	rhs.printAttibute(4);
	out << ".";
	return (out);
}