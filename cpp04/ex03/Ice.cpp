/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:16:41 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/24 18:29:14 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	// std::cout << "(Ice) Defualt constructor is called." << std::endl;
}

Ice::~Ice(void)
{
	// std::cout << "(Ice) Deconstructor is called." << std::endl;
}

Ice *Ice::clone(void) const
{
	return (new Ice ());
}

void	Ice::use(ICharacter &taget)
{
	std::cout << "* shoots an ice bolt at " << taget.getName() << " *" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, Ice &rhs)
{
	out << "(Ice): type[ " << rhs.getType() << " ]" << std::endl;
	return (out);
}