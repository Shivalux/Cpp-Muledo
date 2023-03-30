/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:49:01 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/31 14:54:31 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	// std::cout << "(Cure) Defualt constructor is called." << std::endl;
}

Cure::~Cure(void)
{
	// std::cout << "(Cure) Destructorr is called." << std::endl;
}

Cure	*Cure::clone(void) const
{
	return (new Cure());
}

void	Cure::use(ICharacter &taget)
{
	std::cout << "* heals " << taget.getName() << "'s wounds *" << std::endl;
}

std::ostream &operator<<(std::ostream &out, Cure &rhs)
{
	std::cout << "(Cure): type[ " << rhs.getType() << " ]" << std::endl;
	return (out);
}