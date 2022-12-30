/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:38:23 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/17 16:10:07 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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

	// std::cout << "=============================== ex01 ===============================\n" << std::endl;
	// ScavTrap	scav1;
	// ScavTrap	scav2("serena");
	// ScavTrap	scav3(scav1);

	// std::cout << "\n(line:42) scav1: " << scav1 << std::endl;
	// std::cout << "(line:43) scav2: " << scav2 << std::endl;
	// std::cout << "(line:44) scav3: " << scav3 << std::endl;
	// scav1 = scav2;
	// std::cout << "(line:46) scav1: " << scav1 << std::endl;
	// std::cout << "(line:47) ";
	// scav1.attack("enemy042");
	// std::cout << "(line:49) ";
	// scav1.takeDamage(5);
	// std::cout << "(line:51) ";
	// scav1.beRepaired(1);
	// std::cout << "(line:53) ";
	// scav1.guandGate();
	// std::cout << "(line:55) scav1: " << scav1 << std::endl;
	// std::cout << std::endl;

	// std::cout << "=============================== ex02 ===============================\n" << std::endl;
	// FragTrap	frag1;
	// FragTrap	frag2("sharnvon");
	// FragTrap	frag3(frag1);

	// std::cout << "\n(line:64) frag1: " << frag1 << std::endl;
	// std::cout << "(line:65) frag2: " << frag2 << std::endl;
	// std::cout << "(line:66) frag3: " << frag3 << std::endl;
	// frag1 = frag2;
	// std::cout << "(line:68) frag1: " << frag1 << std::endl;
	// std::cout << "(line:69) ";
	// frag1.attack("enemy042");
	// std::cout << "(line:71) ";
	// frag1.takeDamage(5);
	// std::cout << "(line:73) ";
	// frag1.beRepaired(1);
	// std::cout << "(line:75) ";
	// frag1.highFiveGuy();
	// std::cout << "(line:77) frag1: " << frag1 << std::endl;
	// std::cout << std::endl;

	std::cout << "=============================== ex03 ===============================\n" << std::endl;
	DiamondTrap	diamond1;
	DiamondTrap	diamond2("catEyes");
	DiamondTrap	diamond3(diamond1);

	std::cout << "\n(line:86) diamaond1: " << diamond1 << std::endl;
	std::cout << "(line:87) diamond2: " << diamond2 << std::endl;
	std::cout << "(line:88) diamond3: " << diamond3 << std::endl;
	diamond1 = diamond2;
	std::cout << "(line:90) diamond1: " << diamond1 << std::endl;
	std::cout << "(line:91) ";
	diamond1.attack("enemy042");
	std::cout << "(line:91) ";
	diamond1.takeDamage(5);
	std::cout << "(line:95) ";
	diamond1.beRepaired(1);
	std::cout << "(line:97) ";
	diamond1.whoAmI();
	std::cout << "(line:99) diamond1: " << diamond1 << std::endl;
	std::cout << std::endl;
	return (0);
}