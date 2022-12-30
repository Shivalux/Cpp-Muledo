/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:21:26 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/30 23:15:38 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("NO-NOME"), _signed(0), _gradeSign(150), _gradeExec(150)
{
	std::cout << "(Form) Defualt construrctor is called." << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExec)
	: _name(name), _signed(0), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	std::cout << "(Form) Constructor is called." << std::endl;
	if (gradeSign > 150 || gradeExec > 150)
		throw (Form::GradeTooLowException ());
	if (gradeSign < 1 || gradeExec < 1)
		throw (Form::GradeTooHightException ());
}

Form::Form(Form &src)
	: _name(src._name), _signed(src._signed), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec)
{
	std::cout << "(Form) Copy constuctor is called." << std::endl;
}

Form::~Form(void)
{
	std::cout << "(Form) Deconstructor is called." << std::endl;
}

Form	&Form::operator=(Form const &rhs)
{
	std::cout << "(Form) Copy operator assignment is called." << std::endl;
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
	}
	return (*this);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (this->_gradeSign < bureaucrat.getGrade())
		throw (Form::GradeTooLowException ());
	this->_signed = 1;
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	&Form::getSigned(void)
{
	return (this->_signed);
}

int	Form::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int	Form::getGradeExec(void) const
{
	return (this->_gradeExec);
}

std::ostream	&operator<<(std::ostream &out, Form &rhs)
{
	std::cout << "(Form)[ " << rhs.getName() << " ]";
	std::cout << " signed[ " << rhs.getSigned() << " ]";
	std::cout << " gradeSign[ " << rhs.getGradeSign() << " ]";
	std::cout << " gradeExec[ " << rhs.getGradeExec() << " ]";
	return (out);
}