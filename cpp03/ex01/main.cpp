/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:38:23 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/17 14:49:41 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	// std::cout << "=============================== ex00 ===============================\n" << std::endl;
	// ClapTrap	a;
	// ClapTrap	b("naruto");
	// ClapTrap	c(b);

	// std::cout << "\n(line:22) a: " << a << std::endl;
	// std::cout << "(line:23) b: " << b << std::endl;
	// std::cout << "(line:24) c: " << c << std::endl;
	// a = c;
	// std::cout << "(line:26) a: " << a << std::endl;
	// std::cout << "(line:27) ";
	// a.attack("sasuke");
	// std::cout << "(line:29) ";
	// a.takeDamage(5);
	// std::cout << "(line:31) ";
	// a.beRepaired(1);
	// std::cout << "(line:33) a: " << a << std::endl;
	// std::cout << std::endl;

	std::cout << "=============================== ex01 ===============================\n" << std::endl;
	ScavTrap	scav1;
	ScavTrap	scav2("serena");
	ScavTrap	scav3(scav1);

	std::cout << "\n(line:42) scav1: " << scav1 << std::endl;
	std::cout << "(line:43) scav2: " << scav2 << std::endl;
	std::cout << "(line:44) scav3: " << scav3 << std::endl;
	scav1 = scav2;
	std::cout << "(line:46) scav1: " << scav1 << std::endl;
	std::cout << "(line:47) ";
	scav1.attack("enemy042");
	std::cout << "(line:49) ";
	scav1.takeDamage(5);
	std::cout << "(line:51) ";
	scav1.beRepaired(1);
	std::cout << "(line:53) ";
	scav1.guandGate();
	std::cout << "(line:55) scav1 :" << scav1 << std::endl;
	std::cout << std::endl;
	return (0);
}