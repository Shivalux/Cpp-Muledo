/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:21:26 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/31 14:54:31 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("NO-NOME"), _signed(0), _gradeSign(150), _gradeExec(150)
{
	std::cout << "(AForm) Defualt construrctor is called." << std::endl;
}

AForm::AForm(std::string name, int gradeSign, int gradeExec)
	: _name(name), _signed(0), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	std::cout << "(AForm) Constructor is called." << std::endl;
	if (gradeSign > 150 || gradeExec > 150 || gradeSign < 1 || gradeExec < 1)
		throw (AForm::GradeisOutOFRange ());
}

AForm::AForm(AForm &src)
	: _name(src._name), _signed(src._signed), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec)
{
	std::cout << "(AForm) Copy constuctor is called." << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "(AForm) Destructorr is called." << std::endl;
}

AForm	&AForm::operator=(AForm const &rhs)
{
	std::cout << "(AForm) Copy operator assignment is called." << std::endl;
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
	}
	return (*this);
}

void	AForm::setSigned(bool sign)
{
	this->_signed = sign;
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSigned(void) const
{
	return (this->_signed);
}

int	AForm::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int	AForm::getGradeExec(void) const
{
	return (this->_gradeExec);
}

std::ostream	&operator<<(std::ostream &out, AForm &rhs)
{
	std::cout << "(AForm)[ " << rhs.getName() << " ]";
	std::cout << " signed[ " << rhs.getSigned() << " ]";
	std::cout << " gradeSign[ " << rhs.getGradeSign() << " ]";
	std::cout << " gradeExec[ " << rhs.getGradeExec() << " ]";
	return (out);
}