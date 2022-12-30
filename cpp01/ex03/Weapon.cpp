/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:39:48 by sharnvon          #+#    #+#             */
/*   Updated: 2022/11/01 15:58:16 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	this->_type = "";
}

Weapon::Weapon(std::string set) : _type(set) {}

Weapon::~Weapon(void)
{
	std::cout << "• " << this->_type << "the weapon has been destroyed" << std::endl;
}

std::string const &Weapon::getType(void) const
{
	return (this->_type);
}

void	Weapon::setType(std::string set)
{
	this->_type = set;
}