/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:32:21 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/18 23:41:14 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	std::cout << "=========================== Animal-Class ===========================\n" << std::endl;
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	std::cout << "\n(line:23) dogType: " << j->getType() << " " << std::endl;
	std::cout << "(line:24) catType: " << i->getType() << " " << std::endl;
	std::cout << "(line:28) catSound >> ";
	i->makeSound();
	std::cout << "(line:30) dogSound >> ";
	j->makeSound();
	std::cout << std::endl;
	delete i;
	delete j;

	std::cout << "=========================== Array of Animal ===========================\n" << std::endl;
	int		amount = 4;
	Animal	*array[amount];

	for (int i = 0; i < amount; i++)
	{
		if (i < amount / 2)
			array[i] = new Dog();
		else
			array[i] = new Cat();
	}
	std::cout << "\n(line:44) inside of the array" << std::endl;
	for (int i = 0; i < amount; i++)
		std::cout << "type of array [" << i << "] >> " << array[i]->getType() << std::endl;
	((Cat *)array[2])->getBrain()->getIdea(1) = "Humannnn, feed me now!!!!!";
	std::cout << "(line:48) idea[2]-[" << ((Cat *)array[2])->getBrain()->getIdea(1) << "] -> ["
		<< &((Cat *)array[2])->getBrain()->getIdea(1) << "]" << std::endl;
	std::cout << "(line:50) idea[3]-[" << ((Cat *)array[3])->getBrain()->getIdea(1) << "] -> ["
		<< &((Cat *)array[3])->getBrain()->getIdea(1) << "]" << std::endl;
	*(Cat *)array[3] = *(Cat *)array[2];
	std::cout << "(line:53) idea[2]-[" << ((Cat *)array[2])->getBrain()->getIdea(1) << "] -> ["
		<< &((Cat *)array[2])->getBrain()->getIdea(1) << "]" << std::endl;
	std::cout << "(line:55) idea[3]-[" << ((Cat *)array[3])->getBrain()->getIdea(1) << "] -> ["
		<< &((Cat *)array[3])->getBrain()->getIdea(1) << "]" << std::endl;

	Animal *copyCat = new Cat(*(Cat *)array[2]);
	
	std::cout << "(line:60) copyCat" << ((Cat *)copyCat)->getBrain()->getIdea(1) << "] -> ["
		<< &((Cat *)copyCat)->getBrain()->getIdea(1) << "]" << std::endl;
	std::cout << std::endl;
	delete copyCat;
	for (int i = 0; i < amount; i++)
		delete array[i];
	return (0);
}