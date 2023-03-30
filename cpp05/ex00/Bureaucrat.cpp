/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:28:14 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/31 14:54:31 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("NO-NAME"), _grade(150)
{
	std::cout << "(Bureaucrat) Defualt constructor is called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "(Bureaucrat) Constuctor is called." << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHightException ();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &src)
{
	std::cout << "(Bureaucrat) Copy constructor is called." << std::endl;
	this->_name = src._name;
	this->_grade = src._grade;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "(Bureaucrat) Destructorr is called." << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat &rhs)
{
	std::cout << "(Bureaucrat) Copy assignment is called." << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_grade = rhs._grade;
	}
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::gradeIncreament(void)
{
	
	if (this->_grade - 1 < 1)
		throw (Bureaucrat::GradeTooHightException ());
	this->_grade -= 1;
}

void	Bureaucrat::gradeIncreament(int grade)
{
	if (this->_grade - grade < 1)
		throw (Bureaucrat::GradeTooHightException ());
	this->_grade -= grade;
}

void	Bureaucrat::gradeDecreament(void)
{
	if (this->_grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException ());
	this->_grade += 1;
}

void	Bureaucrat::gradeDecreament(int grade)
{
	if (this->_grade + grade > 150)
		throw (Bureaucrat::GradeTooLowException ());
	this->_grade += grade;
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (out);
}