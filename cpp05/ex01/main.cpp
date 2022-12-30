/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:12:19 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/30 23:22:03 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main(void)
{
	std::cout << "================= Testing-Constructor =================" << std::endl;
	try
	{
		std::cout << "(line:22) Form-innitialise" << std::endl;
		Form	formA("test_form", 151, 151);
		std::cout << "(line:24) success created the from!!" << std::endl << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << "(line28) >>ERROR: Requirement " << exception.what() << ", (hint) range must between 1 to 150." <<std::endl;
	}

	std::cout << "================= Signed-Form =================" << std::endl;
	Bureaucrat	bureaucratA("Supacharasai", 42);
	Form		formA("Standard-Form", 42, 42);
	Form		formB("TopTwentyForm", 20, 20);

	std::cout << "\n(line:36) " << bureaucratA << std::endl;
	std::cout << "(line:37) " << formA << std::endl;
	std::cout << "(line:38) " << formB << std::endl;
	std::cout << std::endl;
	try
	{
		std::cout << "(line:42) [ " << bureaucratA.getName() << " ] try to sign [ " << formA.getName() << " ]" << std::endl;
		bureaucratA.signForm(formA);
	}
	catch (std::exception &exception)
	{
		std::cerr << "(line:47) " << exception.what() << std::endl;
	}
	try
	{
		std::cout << "(line:51) [ " << bureaucratA.getName() << " ] try to sign [ " << formB.getName() << " ]" << std::endl;
		bureaucratA.signForm(formB);
	}
	catch (std::exception &exception)
	{
		std::cerr << "(line:56) " << exception.what() << std::endl;
	}
	std::cout << "\n(line:58) " << bureaucratA << std::endl;
	std::cout << "(line:59) " << formA << std::endl;
	std::cout << "(line:60) " << formB << std::endl;
	std::cout << std::endl;
	return (0);
}