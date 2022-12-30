/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:22:29 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/29 18:11:50 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <ctime>

int main(void)
{
	srand(time(NULL));
	std::list<int>		listInt;
	std::vector<int>	vectorInt;
	int					value;
	int					size = 10;
	int					findNumber = 42;
	
	std::cout << "=============== list-Test ===============" << std::endl;
	std::cout << "lsitInt --> ";
	for (int i = 0; i < size; i++)
	{
		value = rand() % 50;
		listInt.push_back(value);
		std::cout << "[" << value  << "] ";
	}
	try
	{
		std::cout << "\nfind[ " << findNumber << " ]" << std::endl; 
		int result = easyfind(listInt, findNumber);	
		std::cout << "result: FOUND[ " << result << " ]" << std::endl;
	}
	catch (std::string &exception)
	{
		std::cout << "result: " << exception << std::endl;
	}
	std::cout << "=============== vector-Test ===============" << std::endl;
	std::cout << "vectorInt --> ";
	for (int i = 0; i < size; i++)
	{
		value = rand() % 50;
		vectorInt.push_back(value);
		std::cout << "[" << value  << "] ";
	}
	try
	{
		std::cout << "\nfind[ " << findNumber << " ]" << std::endl; 
		int result = easyfind(vectorInt, findNumber);	
		std::cout << "result: FOUND[ " << result << " ]" << std::endl;
	}
	catch (std::string &exception)
	{
		std::cout << "result: " << exception << std::endl;
	}
	return (0);
}