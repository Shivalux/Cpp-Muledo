/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 03:35:25 by sharnvon          #+#    #+#             */
/*   Updated: 2022/11/02 23:06:42 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::complain(std::string level)
{
	void		(Harl::*functionPointer[4])(void);
	std::string	levelMode[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			index;

	index = 0;
	functionPointer[0] = &Harl::debug;
	functionPointer[1] = &Harl::info;
	functionPointer[2] = &Harl::warning;
	functionPointer[3] = &Harl::error;
	while(index < 4 && level.compare(levelMode[index]))
		index++;
	switch(index)
	{
		case 0:
			(this->*functionPointer[0])();
			std::cout << std::endl;
		case 1:
			(this->*functionPointer[1])();
			std::cout << std::endl;
		case 2:
			(this->*functionPointer[2])();
			std::cout << std::endl;
		case 3:
			(this->*functionPointer[3])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-dubble-cheese-trinple-pickle-special-ketchup buger." << std::endl;
	std::cout << "I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot belive adding extra bacon costs more money." << std::endl;
	std::cout << "You didn't put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WANRNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years whereas you started woking here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable!" << std::endl;
	std::cout << "I want to speak with manager now." << std::endl;
}