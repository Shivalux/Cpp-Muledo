/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:37:24 by sharnvon          #+#    #+#             */
/*   Updated: 2022/11/02 23:05:07 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	Harl		harl;
	std::string	level;

	if (argc != 2)
	{
		std::cout << "error: wrong arguments" << std::endl;
		std::cout << "(hint)  $>./harlFilter [level of comments Harl make]" << std::endl;
		std::cout << "(level) | debug | info | warning | error |" << std::endl;
		return (EXIT_FAILURE);
	}
	for (int i = 0; argv[1][i] != '\0'; i++)
		level += toupper(argv[1][i]);
	harl.complain(level);
	return (EXIT_SUCCESS);
}