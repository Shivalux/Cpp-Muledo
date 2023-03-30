/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:11:31 by sharnvon          #+#    #+#             */
/*   Updated: 2023/03/30 23:15:12 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static std::string	argumentCheck(int argc, char **argv, std::deque<char> &container);

RPN::RPN(void)
{
	std::cout << "[RPN] default constructor is called." << std::endl;
}

RPN::RPN(int argc, char ** argv)
{
	std::cout << "[RPN] constructor is called." << std::endl;
	this->_RPN = argumentCheck(argc, argv, this->_IN);
	this->_result = this->_IN[0] - '0';
	for (int i = 1; this->_IN[i]; ++i)
	{
		if (this->_IN[i] == '+')
			this->_result += this->_IN[++i] - '0';
		else if (this->_IN[i] == '-')
			this->_result -= this->_IN[++i] - '0';
		else if (this->_IN[i] == '*')
			this->_result *= this->_IN[++i] - '0';
		else if (this->_IN[i] == '/')
			this->_result /= this->_IN[++i] - '0';
	}
}

RPN::~RPN(void)
{
	std::cout << "[RPN] destructor is called." << std::endl;
}

RPN::RPN(RPN const &src)
{
	std::cout << "[RPN] copy-constrcutor is called." << std::endl;
	this->_RPN = src._RPN;
	this->_result = src._result;
	this->_IN = src._IN;
}

RPN	&RPN::operator=(RPN const &rhs)
{
	std::cout << "[RPN] copy-assignment operator is called." <<std::endl;
	if (this != &rhs)
	{
		this->_RPN = rhs._RPN;
		this->_result = rhs._result;
		this->_IN = rhs._IN;
	}
	return (*this);
}

int		RPN::getResult(void)
{
	return (this->_result);
}

std::string	RPN::getRPN(void)
{
	return (this->_RPN);
}

void	RPN::printIN(void)
{
	for (int i = 0; this->_IN[i]; ++i)
		std::cout << this->_IN[i] << " ";
}

std::ostream	&operator<<(std::ostream &c, RPN &rhs)
{
	c << "RPN   : " << rhs.getRPN() << std::endl;
	c << "IN    : ";
	rhs.printIN();
	c << "\nresult: " << rhs.getResult();
	return (c);
}

static std::string	argumentCheck(int argc, char **argv, std::deque<char> &container)
{
	int			countOperator = 0;
	int			countDigit = 0;
	int			check = 0;
	int 		position;
	std::string	result;

	if (argc != 2)
		throw (RPN::InvalidArguments());
	for (int i = 0; i < argv[1][i]; i++)
	{
		if (isdigit(argv[1][i]))
		{
			container.push_back(argv[1][i]);
			container.push_back('\0');
			result += argv[1][i];
			countDigit++;
			check++;
		}
		else if (strchr("+-*/", argv[1][i]) && container.size())
		{
			position = container.size() - 2;
			for (;position >= 0 && container[position]; --position);
			if (position < 0)
				throw (RPN::InvalidFomatArguments());
			container[position] = argv[1][i];
			result += argv[1][i];
			countOperator++;
			check++;
		}
		else if (argv[1][i] == ' ')
		 {
			if (check > 1)
				throw (RPN::InvalidFomatArguments());
			result += ' ';
			check = 0;
		 }
		 else
		 	throw (RPN::InvalidFomatArguments());
	}
	if (countDigit < 2 || countOperator < 1 || countDigit != countOperator + 1)
		throw (RPN::InvalidFomatArguments());
	return (result);
}