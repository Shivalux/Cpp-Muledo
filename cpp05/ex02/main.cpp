/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:12:19 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/30 23:34:39 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>
#include <iostream>

int main(void)
{
	ShrubberyCreationForm	formA("Thanlai");
	RobotomyRequestForm		formB("Pritva");
	PresidentialPardonForm	formC("Pruyatte");
	Bureaucrat				bureaucratA("Supacharasai", 5);
	
	std::cout << std::endl;
	std::cout << "(line:29) " << bureaucratA << std::endl;
	std::cout << "(line:30) " << formA << std::endl;
	std::cout << "(line:31) " << formB << std::endl;
	std::cout << "(line:32) " << formC << std::endl << std::endl;
	
	try
	{
		std::cout << "(line:37) [ " << bureaucratA.getName() << " ] try to signed [ " << formA.getName() << " ]"<< std::endl;
		bureaucratA.signForm(formA);
		std::cout << "(line:39) [ " << bureaucratA.getName() << " ] try to execute [ " << formA.getName() << " ]"<< std::endl;
		bureaucratA.executeForm(formA);
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	try
	{
		std::cout << "\n(line:48) [ " << bureaucratA.getName() << " ] try to signed [ " << formB.getName() << " ]"<< std::endl;
		bureaucratA.signForm(formB);
		std::cout << "(line:50) [ " << bureaucratA.getName() << " ] try to execute [ " << formB.getName() << " ]"<< std::endl;
		bureaucratA.executeForm(formB);
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	try
	{
		std::cout << "\n(line:59) [ " << bureaucratA.getName() << " ] try to signed [ " << formC.getName() << " ]"<< std::endl;
		bureaucratA.signForm(formC);
		std::cout << "(line:61) [ " << bureaucratA.getName() << " ] try to execute [ " << formC.getName() << " ]"<< std::endl;
		bureaucratA.executeForm(formC);
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "(line:68) " << bureaucratA << std::endl;
	std::cout << "(line:69) " << formA << std::endl;
	std::cout << "(line:70) " << formB << std::endl;
	std::cout << "(line:71) " << formC << std::endl << std::endl;
	return (0);
}