/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:24:05 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/20 15:04:27 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main(void)
{
	std::cout << "==================== MainFromPDF ====================" << std::endl;
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << std::endl;
	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	std::cout << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;

	std::cout << "\n==================== CharacterDeepCopy ====================" << std::endl;
	Character CopyMe;
	CopyMe = *(Character *)me;
	std::cout  << *(Character *)me << std::endl;
	std::cout  << CopyMe << std::endl;

	std::cout << "\n==================== MateriaDeepCopy ====================" << std::endl;
	MateriaSource CopyMateria;
	CopyMateria = *(MateriaSource *)src;
	std::cout  << *(MateriaSource *)src << std::endl;
	std::cout  << CopyMateria << std::endl;

	std::cout << "\n==================== Unequuip ====================" << std::endl;
	tmp = ((Character *)me)->getSlot()[0];
	me->unequip(0);
	delete tmp;

	delete bob;
	delete me;
	delete src;
	
	return (0);
}