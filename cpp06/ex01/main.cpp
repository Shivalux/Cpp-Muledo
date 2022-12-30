/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:26:51 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/27 01:23:35 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialization.hpp"
#include <iostream>
#include <ctime>

uintptr_t	serialize(Data *pointer);
Data		*deserialize(uintptr_t raw);

int main(void)
{
	Data		*dataPointer;
	Data		dataValue;
	uintptr_t	uintPointer = 0;

	srand(time(NULL));
	dataValue.structMember1 = rand() % 1000;
	dataValue.structMember2 = rand() % 1000;
	dataValue.structMember3 = rand() % 1000;
	dataValue.structMember4 = rand() % 1000;
	dataValue.structMember5 = rand() % 1000;
	dataPointer = &dataValue;
	std::cout << "================== " << std::endl;
	std::cout << "(line:34) address [" << dataPointer << "]		-|" << std::endl;
	std::cout << "(line:35) member1 [" << dataPointer->structMember1 << "]			 |" << std::endl;
	std::cout << "(line:36) member2 [" << dataPointer->structMember2 << "]			 |" << std::endl;
	std::cout << "(line:37) member3 [" << dataPointer->structMember3 << "]			 |---- [ before serialize() ]" << std::endl;
	std::cout << "(line:38) member4 [" << dataPointer->structMember4 << "]			 |" << std::endl;
	std::cout << "(line:39) member5 [" << dataPointer->structMember5 << "]			 |"<< std::endl;
	std::cout << "(line:40) uintPtr ["<< uintPointer << "]			-|" <<std::endl;
	std::cout << "================== " << std::endl;
	uintPointer = serialize(dataPointer);
	dataPointer = NULL;
	std::cout << "(line:44) uintPtr ["<< uintPointer << "]		------ [ after serialize() ]" <<std::endl;
	std::cout << "(line:45) address [" << dataPointer << "]			------ [ set dataPointer to NULL ]" << std::endl;
	dataPointer = deserialize(uintPointer);
	std::cout << "====================" << std::endl;
	std::cout << "(line:48) address [" << dataPointer << "]		-|" << std::endl;
	std::cout << "(line:49) member1 [" << dataPointer->structMember1 << "]			 |" << std::endl;
	std::cout << "(line:50) member2 [" << dataPointer->structMember2 << "]			 |" << std::endl;
	std::cout << "(line:51) member3 [" << dataPointer->structMember3 << "]			 |---- [ after deserialize() ]" << std::endl;
	std::cout << "(line:52) member4 [" << dataPointer->structMember4 << "]			 |" << std::endl;
	std::cout << "(line:53) member5 [" << dataPointer->structMember5 << "]			 |"<< std::endl;
	std::cout << "(line:54) uintPtr ["<< uintPointer << "]		-|" <<std::endl;
	std::cout << "================== " << std::endl;
	return (0);
}

uintptr_t	serialize(Data *pointer)
{
	return (reinterpret_cast<uintptr_t>(pointer));
}

Data	*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
