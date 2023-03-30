/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:12:19 by sharnvon          #+#    #+#             */
/*   Updated: 2023/03/28 09:59:10 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <exception>
#include <iostream>

int main(void)
{
	Bureaucrat	bureaucratA("Supacharasai", 50);
	Intern		intern;
	AForm		*formA;
	
	std::cout << std::endl;
	std::cout << "(line:29) " << bureaucratA << std::endl;
	std::cout << "(line:30) " << intern << std::endl;
	formA = intern.makeForm("Shrubbery-Creation", "Pruyatte");
	std::cout << "(line:32) " << intern << std::endl;	
	try
	{
		if (formA != NULL)
		{
			std::cout << "\n(line:38) [ " << bureaucratA.getName() << " ] try to signed [ " << formA->getName() << " ]"<< std::endl;
			bureaucratA.signForm(*formA);
			std::cout << "(line:40) [ " << bureaucratA.getName() << " ] try to execute [ " << formA->getName() << " ]"<< std::endl;
			bureaucratA.executeForm(*formA);
		}
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	std::cout << std::endl;
	formA = intern.makeForm("Robotomy-Request", "Pruyatte");
	try
	{
		if (formA != NULL)
		{
			std::cout << "\n(line:54) [ " << bureaucratA.getName() << " ] try to signed [ " << formA->getName() << " ]"<< std::endl;
			bureaucratA.signForm(*formA);
			std::cout << "(line:56) [ " << bureaucratA.getName() << " ] try to execute [ " << formA->getName() << " ]"<< std::endl;
			bureaucratA.executeForm(*formA);
		}
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	std::cout << std::endl;
	formA = intern.makeForm("Presidential-Pardon", "Pruyatte");
	try
	{
		if (formA != NULL)
		{
			std::cout << "\n(line:70) [ " << bureaucratA.getName() << " ] try to signed [ " << formA->getName() << " ]"<< std::endl;
			bureaucratA.signForm(*formA);
			std::cout << "(line:72) [ " << bureaucratA.getName() << " ] try to execute [ " << formA->getName() << " ]"<< std::endl;
			bureaucratA.executeForm(*formA);
		}
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "(line:80) " << bureaucratA << std::endl;
	std::cout << "(line:81) " << intern << std::endl;
	std::cout << std::endl;
	Intern	a(intern);
	return (0);
}