/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:23:37 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/24 18:29:14 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "(DiamondTrap) Defualt constructor is called." << std::endl;
	this->DiamondTrap::_name = "NO_NAME";
	ClapTrap::_name = this->_name + "_clap_name";
	ScavTrap::_energyPoints = 50;
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "(DiamondTrap) Constructor is called." << std::endl;
	this->DiamondTrap::_name = name;
	ClapTrap::_name = this->_name + "_clap_name";
	ScavTrap::_energyPoints = 50;
}

DiamondTrap::DiamondTrap(DiamondTrap &src)
{
	std::cout << "(DiamondTrap) Constructor is called." << std::endl;
	this->DiamondTrap::_name = src._name;
	ClapTrap::_name = src._name + "_clap_name";
	ScavTrap::_energyPoints = 50;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "(DiamondTrap) Deconstructor is called." << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap &rhs)
{
	std::cout << "(DiamondTrap) Copy assignment operator is called." << std::endl;
	if (this != &rhs)
	{
		this->DiamondTrap::_name = rhs._name;
		ClapTrap::_name = rhs.ClapTrap::_name;
		this->_energyPoints = rhs._energyPoints;
		this->_hitPoints = rhs._hitPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	std::cout << this->_name << " has taken damage " << amount << " points, decreased its hitpoint from "
		<< this->_hitPoints;
	if (this->_hitPoints - amount < 0)
		this->_hitPoints = 0;
	this->_hitPoints -= amount;
	std::cout << " to " << this->_hitPoints << "." << std::endl;
}

void	DiamondTrap::beRepaired(unsigned int amount)
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

void	DiamondTrap::whoAmI(void)
{
	std::cout << "(DiamondTrap) name[" << this->_name << "], clapTrapName[" << ClapTrap::_name << "]" << std::endl;
}

std::string	DiamondTrap::getName(void)
{
	return (this->_name);
}

std::ostream	&operator<<(std::ostream &out, DiamondTrap &rhs)
{
	out << "(DiamondTrap) name[" << rhs.getName();
	out << "], clapTrapName[";
	rhs.printAttibute(1);
	out << "], hitPoints[";
	rhs.printAttibute(2);
	out << "], energyPoints[";
	rhs.printAttibute(3);
	out << "], attackDamage[";
	rhs.printAttibute(4);
	out << "].";
	return (out);
}