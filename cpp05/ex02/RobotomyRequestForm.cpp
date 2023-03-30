/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 08:26:19 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/31 14:54:31 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy-Requset", 72, 45), _taget("NOTHING")
{
	std::cout << "(RobotomyRequestForm) Defualt constructor is called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string taget) : AForm("Robotomy-Request", 72, 45), _taget(taget)
{
	std::cout << "(RobotomyRequestForm) Construrtor is called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src)
{
	std::cout << "(RobotomyRequestForm) Copy constructor is called." << std::endl;
	this->setSigned(src.getSigned());
	this->_taget = src._taget;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "(RobotomyRequestForm) Destructorr is called." << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm &rhs)
{
	std::cout << "(RobotomyRequestForm) Copy assignment is called." << std::endl;
	if (this != &rhs)
	{
		this->setSigned(rhs.getSigned());
		this->_taget = rhs._taget;
	}
	return (*this);
}

void	RobotomyRequestForm::beSigned(Bureaucrat &bureaucrat)
{
	if (this->getGradeSign() < bureaucrat.getGrade())
		throw (RobotomyRequestForm::GradeTooLowException ());
	this->setSigned(1);
}

void	RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const
{
	int result;

	if (this->getSigned() == 0)
		throw (RobotomyRequestForm::FormNotSigned ());
	if (this->getGradeExec() < bureaucrat.getGrade())
		throw (RobotomyRequestForm::GradeTooLowException ());
	srand(time(NULL));
	std::cout << "drilling sound ~" << std::endl;
	usleep(500000);
	std::cout << "drilling sound ~" << std::endl;
	usleep(500000);
	std::cout << "drilling sound ~" << std::endl;
	usleep(500000);
	result = rand() % 2;
	if (result == 1)
		std::cout << "[ RESULT " << result << " ] [ " << this->_taget << " ] has been robotomized." << std::endl;
	else
		std::cout << "[ RESULT " << result << " ] the robotomy failed, better win 50/50 next time." << std::endl;
}

std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm &rhs)
{
	std::cout << "(RobotomyRequestForm)    _signed[ ";
	if (rhs.getSigned() == 1)
		std::cout << "true ]";
	if (rhs.getSigned() == 0)
		std::cout << "false ]";
	std::cout << " | gradeSign[ 72 ] gradeExec [ 45 ]";
	return (out);
}