/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:45:44 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/24 20:22:22 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int Intern::_count = 0;

Intern::Intern(void)
{
	std::cout << "(Intern) Defualt constructor is called." << std::endl;
	for (int i = 0; i < 1000; i++)
		this->_formAddress[i] = NULL;
}

Intern::Intern(Intern &src)
{
	std::cout << "(Intern) Copy constructor is called." << std::endl;
	this->_count = src._count;
	for (int i = 0; i < 1000; i++)
	{
		if (i < this->_count)
			this->_formAddress[i] = src._formAddress[i];
		else
			this->_formAddress[i] = NULL;
	}
}

Intern::~Intern(void)
{
	std::cout << "(Intern) Deconstructor is called." << std::endl;
	for (int i = 0; i < _count; i++)
	{
		try
		{
			delete this->_formAddress[i];
		}
		catch(const std::exception &exception)
		{
			std::cerr << exception.what() << std::endl;
		}
	}
}

Intern	&Intern::operator=(Intern &rhs)
{
	std::cout << "(Intern) Copy assignment is called." << std::endl;
	if (this != &rhs)
	{
		this->_count = rhs._count;
		for (int i = 0; i < 1000; i++)
		{
			if (i < this->_count)
				this->_formAddress[i] = rhs._formAddress[i];
			else
				this->_formAddress[i] = NULL;
		}
	}
	return (*this);
}

AForm	**Intern::getFormAddress(void)
{
	return (this->_formAddress);
}

int		Intern::getCount(void) const
{
	return (_count);
}

AForm	*Intern::makeForm(std::string formName, std::string taget)
{
	std::string existForms[] = {"shrubbery-creation", "robotomy-request", "presidential-pardon"};
	AForm		*form = NULL;
	std::string	name = "";
	int 		index = 0;

	for (int i = 0; formName[i] != '\0'; i++)
		name += tolower(formName[i]);
	while (index < 3 && name.compare(existForms[index]) != 0)
	{
		index++;
	}
	switch (index)
	{
		case 0 :
			form = new ShrubberyCreationForm(taget);
			std::cout << "(Intern) Shrubbery-Creation Form was created!!" << std::endl;
			break;
		case 1 :
			form = new RobotomyRequestForm(taget);
			std::cout << "(Intern) Robotomy-Request Form was created!!" << std::endl;
			break;
		case 2 :
			form = new PresidentialPardonForm(taget);
			std::cout << "(Intern) Presidential-Pardon Form was created!!" << std::endl;
			break;
		default :
			std::cout << " ERROR: form[ " << formName << " ] doesn't exist....." << std::endl;
			break;
	}
	if (form != NULL)
		this->_formAddress[this->_count++] = form;
	return (form);
}

std::ostream	&operator<<(std::ostream &out, Intern &rhs)
{
	std::cout << "(Intern) AddressStored[ " << rhs.getCount() << " ]";
	for (int i = 0; rhs.getFormAddress()[i] != NULL; i++)
		std::cout << "\n [" << i << "][ " << rhs.getFormAddress()[i] << " ]";
	return (out);
}