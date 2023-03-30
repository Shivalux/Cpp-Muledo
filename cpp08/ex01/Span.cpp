/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:54:31 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/31 19:45:21 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _n(0)
{
	std::cout << "(Span) Defualt constructor is called." << std::endl;
}

Span::Span(unsigned int n) : _n(n)
{
	std::cout << "(Span) Constructor is called." << std::endl;
}

Span::Span(Span const &src)
{
	std::list<int>::iterator	count;

	std::cout << "(Span) Copy consturctor is called." << std::endl;
	*this = src; 
}

Span::~Span(void)
{
	std::cout << "(Span) Deconsturctor is called." << std::endl;
}

Span	&Span::operator=(Span const &rhs)
{
	std::list<int>::iterator	count;

	std::cout << "(Span) Copy assignment operator is called." << std::endl;
	if (this != &rhs)
	{
		this->_n = rhs._n;
		this->_listNumber = rhs._listNumber;
	}
	return(*this);
}

void	Span::addNumber(int number)
{
	if (this->_listNumber.size() >= this->_n)
		throw (Span::addNumberError ());
	this->_listNumber.push_back(number);
}

int	Span::shortestSpan(void)
{
	std::list<int>				duplicateList;
	std::list<int>::iterator	count0;
	std::list<int>::iterator	count1;
	int							result;

	if (this->_listNumber.size() <= 1)
		throw (Span::shortestSpanError ());
	duplicateList = this->_listNumber;
	count0 = duplicateList.begin();
	count1 = duplicateList.begin();
	result = INT_MAX;
	for (;++count1 != duplicateList.end(); count0++)
	{
		if (abs(*count1 - *count0) < result)
			result = abs(*count1 - *count0);
	}
	return (result);
}

int	Span::longestSpan(void)
{
	std::list<int>	duplicateList;
	int 			result;

	if (this->_listNumber.size() <= 1)
		throw (Span::longestSpanError ());
	duplicateList = this->_listNumber;
	duplicateList.sort();
	result = duplicateList.back() - duplicateList.front();
	return (result);
}

void	Span::addNumberRange(std::list<int>::iterator begin, std::list<int>::iterator end)
{
	for (; begin != end && this->_listNumber.size() < this->_n; begin++)
	{
		this->_listNumber.push_back(*begin);
	}
	if (begin != end)
		std::cout << "(addNumberRange) ERROR: Have not enough space available...." << std::endl;
}

std::list<int> &Span::getListNumber(void)
{
	return (this->_listNumber);
}

unsigned int	Span::getN(void) const
{
	return (this->_n);
}

std::ostream	&operator<<(std::ostream &out, Span &rhs)
{
	std::list<int>::iterator	count;

	std::cout << "(Span)[" << rhs.getListNumber().size() << "|" << rhs.getN() << "] -> ";
	count = rhs.getListNumber().begin();
	for (; count != rhs.getListNumber().end(); count++)
		std::cout << "[" << *count << "] ";
	return (out);
}