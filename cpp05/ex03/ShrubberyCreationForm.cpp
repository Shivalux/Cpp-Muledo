/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:59:16 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/31 14:54:31 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery-Cration", 145, 137), _taget("NOTHING")
{
	std::cout << "(ShrubberyCreation) Defualt constructor is called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string taget) : AForm("Shrubbery_Cration", 145, 137), _taget(taget)
{
	std::cout << "(ShrubberyCration) Constructor is called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src)
{
	std::cout << "(ShrubberyCreationForm) Copy constructor is called." << std::endl;
	this->setSigned(src.getSigned());
	this->_taget = src._taget;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "(ShrubberyCreationForm) Destructorr is called." << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm &rhs)
{
	std::cout << "(ShrubberyCreationForm) Copy assignment is called." << std::endl;
	if (this != &rhs)
	{
		this->setSigned(rhs.getSigned());
		this->_taget = rhs._taget;
	}
	return (*this);
}

void	ShrubberyCreationForm::beSigned(Bureaucrat &bureaucrat)
{
	if (this->getGradeSign() < bureaucrat.getGrade())
		throw (ShrubberyCreationForm::GradeTooLowException ());
	this->setSigned(1);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const
{
	std::ofstream	outFile;
	if (this->getSigned() == 0)
		throw (ShrubberyCreationForm::FormNotSigned ());
	if (this->getGradeExec() < bureaucrat.getGrade())
		throw (ShrubberyCreationForm::GradeTooLowException ());
	outFile.open(this->_taget + "_shrubbery");
	if (!outFile)
	{
		std::cerr << "(ShrubberyCreationForm) ERROR: outfile cannot created." << std::endl;
		return ;
	}
	outFile << "                ,@@@@@@@," << std::endl;
	outFile << "        ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	outFile << "     ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	outFile << "    ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	outFile << "    %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	outFile << "    %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	outFile << "    `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	outFile << "        |o|        | |         | |" << std::endl;
	outFile << "        |.|        | |         | |" << std::endl;
	outFile << "     \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_ " << std::endl;
	outFile << "        >> Shruberry-Creation-Form <<" << std::endl;
	outFile << ">> " << this->_taget << " <<" << std::endl;
	outFile.close();
}


std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm &rhs)
{
	std::cout << "(ShrubberyCreationForm)  _signed[ ";
	if (rhs.getSigned() == 1)
		std::cout << "true ]";
	if (rhs.getSigned() == 0)
		std::cout << "false ]";
	std::cout << " | gradeSign[ 145 ] gradeExec [ 137 ]";
	return (out);
}
