/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:38:23 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/15 21:26:23 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	a;
	ClapTrap	b("naruto");
	ClapTrap	c(b);

	std::cout << "\n(line:21) a: " << a << std::endl;
	std::cout << "(line:22) b: " << b << std::endl;
	std::cout << "(line:23) c: " << c << std::endl;
	a = c;
	std::cout << "(line:25) a: " << a << std::endl;
	std::cout << "(line:27) ";
	a.attack("sasuke");
	std::cout << "(line:28) ";
	a.takeDamage(5);
	std::cout << "(line:30) ";
	a.beRepaired(1);
	std::cout << "(line:32) a: " << a << std::endl;
	std::cout << std::endl;
	return (0);
}