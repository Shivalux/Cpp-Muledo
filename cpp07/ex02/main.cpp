/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:25:56 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/31 17:57:02 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 10

int main(void)
{
	std::cout << "========= Constructor-Test =========" <<std::endl;
	Array<int>	numbers(MAX_VAL);
	Array<int>	emptyArray;
	int			*mirror = new int[MAX_VAL];

	srand(time(NULL));
	std::cout << "========= AccessOperator-Test =========" <<std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = 32 + rand() % 95;
		numbers[i] = value;
		mirror[i] = value;
	}
	std::cout << "(line:33) numbers[" << &numbers << "] --> " << numbers << std::endl;
	std::cout << "(line:34) mirror [" << mirror <<  "] --> ";
	for (int i = 0; i < MAX_VAL; i++) 
		std::cout << "[" << mirror[i] << "]";
	std::cout << std::endl;
	{
	std::cout << "========= CopyConsturctor-Test =========" <<std::endl;
		Array<int> tmp = numbers;
		std::cout << "(line:41) numbers[" << &tmp << "] --> " << tmp << std::endl;
		Array<int> test(tmp);
		std::cout << "(line:43) numbers[" << &test << "] --> " << test << std::endl;
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << "========= OutRange-AccessOperator-Test =========" <<std::endl;
	try
	{
		numbers[-2] = 0;
		emptyArray[0] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "=========  Assgind-NewValue-Test =========" <<std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = 32 + (rand() % 95);
	}
	std::cout << "(line:77) numbers[" << &numbers << "] --> " << numbers << std::endl;
	std::cout << "=========  CopyAssignment-Test =========" <<std::endl;
	Array<int>	CopyConstruct(numbers);
	Array<int>	CopyAssign(MAX_VAL);
	CopyAssign = numbers;
	numbers[0] = 440;
	std::cout << "(line:80) numbers      [" << &numbers[0] << "] --> " << numbers << std::endl;
	std::cout << "(line:81) CopyAssign   [" << &CopyAssign[0] << "] --> " << CopyAssign << std::endl;
	std::cout << "(line:81) CopyConstruct[" << &CopyConstruct[0] << "] --> " << CopyConstruct << std::endl;
	delete [] mirror;
	return (0);
}