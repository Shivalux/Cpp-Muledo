/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:47:23 by sharnvon          #+#    #+#             */
/*   Updated: 2022/10/29 22:46:21 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::phoneBookTable(void)
{
	int	index;

	index = 0;
	std::cout << "---------------------------------------------" << std::endl;
	while (index < 8)
	{
		std::cout << "|" << std::setw(10) << index + 1 << "|";
		if (this->contact[index].cGet(FIRST).length() <= 10)
			std::cout << std::setw(10) << this->contact[index].cGet(FIRST);
		else
			std::cout << std::setw(9) << this->contact[index].cGet(FIRST).erase(9) << ".";
		if (this->contact[index].cGet(LAST).length() <= 10)
			std::cout << "|" << std::setw(10) << this->contact[index].cGet(LAST);
		else
			std::cout << "|" << std::setw(9) << this->contact[index].cGet(LAST).erase(9) << ".";
		if (this->contact[index].cGet(NICK).length() <= 10)
			std::cout << "|" << std::setw(10) << this->contact[index].cGet(NICK) << "|" << std::endl;
		else
			std::cout << "|" << std::setw(9) << this->contact[index].cGet(NICK).erase(9) << ".|" << std::endl;
		index++;
	}
	std::cout << "---------------------------------------------" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
}