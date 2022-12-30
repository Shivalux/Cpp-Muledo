/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:12:19 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/30 22:57:56 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main(void)
{
	std::cout << "=============================== ex00 ===============================" << std::endl;
	try
	{
		std::cout << "(line:23) test constructor with out-range value." << std::endl;
		Bureaucrat	bureaucratA("Supacharasai", 100000);
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	Bureaucrat	bureaucratA("Supacharasai", 42);
	int			value = 200;
	try
	{
		std::cout << "\n(line:34) [decrease grade][ " << value << " ] : " << bureaucratA << std::endl;
		bureaucratA.gradeDecreament(value);
		std::cout << "(line:35) "<< bureaucratA << std::endl;

	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	try
	{
		std::cout << "\n(line:45) [increase grade][ " << value << " ] : " << bureaucratA << std::endl;
		bureaucratA.gradeIncreament(value);
		std::cout << "(line:46) "<< bureaucratA << std::endl;
	}
	catch (const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	std::cout << "\n(line:52) " << bureaucratA << std::endl;
	return (0);
}