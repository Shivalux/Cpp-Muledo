/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 09:42:19 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/31 14:54:31 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential-Pardon", 25, 5), _taget("NOTHING")
{
	std::cout << "(PresidentialPardonForm) Defualt constructor is called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string taget) : AForm("Presidential-Pardon", 25, 5), _taget(taget)
{
	std::cout << "(PresidentialPardonForm) Constructor is called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src)
{
	std::cout << "(PresidentialPardonForm) Copy consturctor is called." << std::endl;
	this->setSigned(src.getSigned());
	this->_taget = src._taget;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "(PresidentialPardonForm) Destructorr is called." << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm &rhs)
{
	std::cout << "(PresidentialPardonForm) Copy assignment is called." << std::endl;
	if (this != &rhs)
	{
		this->setSigned(rhs.getSigned());
		this->_taget = rhs._taget;
	}
	return (*this);
}

void	PresidentialPardonForm::beSigned(Bureaucrat &bureaucrat)
{
	if (this->getGradeSign() < bureaucrat.getGrade())
		throw (PresidentialPardonForm::GradeTooLowException ());
	this->setSigned(1);
}

void	PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const
{
	if (this->getSigned() == 0)
		throw (PresidentialPardonForm::FormNotSigned ());
	if (this->getGradeExec() < bureaucrat.getGrade())
		throw (PresidentialPardonForm::GradeTooLowException ());
	std::cout << "[ " << this->_taget << " ] has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm &rhs)
{
	std::cout << "(PresidentialPardonForm) _signed[ ";
	if (rhs.getSigned() == 1)
		std::cout << "true ]";
	if (rhs.getSigned() == 0)
		std::cout << "false ]";
	std::cout << " | gradeSign[ 25 ] gradeExec [ 5 ]";
	return (out);
}