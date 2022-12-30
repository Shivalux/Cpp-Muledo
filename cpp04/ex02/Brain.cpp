/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:50:32 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/19 16:43:07 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "(Brain) Constructor is called." << std::endl;
}

Brain::Brain(Brain &src)
{
	std::cout << "(Brain) Copy constructor is called." << std::endl;
	for (int i = 0; i < 100; i++)
		this->_idea[i] = src._idea[i];
}

Brain::~Brain(void)
{
	std::cout << "(Brain) Deconstructor is called." << std::endl;
}
// return empty string //
std::string	&Brain::getIdea(int index)
{
	if (index < 100 && index >= 0)
		return (this->_idea[index]);
	std::cout << "(Brin) invalid index, i will random index for U" << std::endl;
	return (this->_idea[index % 99]);
}

Brain	&Brain::operator=(Brain &rhs)
{
	std::cout << "(Brain) Copy assiagnment is called." << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_idea[i] = rhs._idea[i];
	}
	return (*this);
}