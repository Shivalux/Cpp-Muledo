/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:32:21 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/17 22:15:07 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	std::cout << "=========================== Animal-Class ===========================\n" << std::endl;
	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	std::cout << "\n(line:23) dogType: " << j->getType() << " " << std::endl;
	std::cout << "(line:24) catType: " << i->getType() << " " << std::endl;
	std::cout << "(line:28) catSound >> ";
	i->makeSound();
	std::cout << "(line:30) dogSound >> ";
	j->makeSound();
	std::cout << "(line:32) animalSound >> ";
	meta->makeSound();
	std::cout << std::endl;
	delete meta;
	delete i;
	delete j;

	std::cout << "\n======================== WrongAnimal-Class ========================\n" << std::endl;
	const WrongAnimal	*mate = new WrongAnimal();
	const WrongAnimal	*ii = new WrongCat();

	std::cout << "\n(line:41) catType: " << ii->getType() << " " << std::endl;
	std::cout << "(line:42) catSound >> ";
	ii->makeSound();
	std::cout << "(line:44) animalSound >> ";
	mate->makeSound();
	std::cout << std::endl;
	delete mate;
	delete ii;
	return (0);
}