/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:36:23 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/30 22:15:13 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template< typename T >
MutantStack<T>::MutantStack(void)
{
	std::cout << "(MutantStack) Defualt constructor is called." << std::endl;
}

template< typename T >
MutantStack<T>::MutantStack(MutantStack<T> const &src) : std::stack<T>(src)
{
	// std::cout << "(MutantStack) Copy constructor is called." << std::endl;
	// this = src._stackValue;
}

template< typename T >
MutantStack<T>::~MutantStack(void)
{
	// std::cout << "(MutantStack) Deconstructor is called." << std::endl;
}

// template< typename T >
// MutantStack<T>	&MutantStack<T>::operator=(MutantStack<T> const &rhs)
// {
// 	std::cout << "(MutantStack) Copy assignment operator is called." << std::endl;
// 	if (this != &rhs)
// 	{
// 		// MutantStack<T>(rhs);
// 	}
// 	return (*this);
// }

template< typename T>
T	*MutantStack<T>::begin(void)
{
	std::stack<T>	tmpStack;
	T				*iterator = NULL;

	for (;this->size() > 1; this->pop())
		tmpStack.push(this->top());
	iterator = &this->top();
	for (;tmpStack.size() > 0; tmpStack.pop())
		this->push(tmpStack.top());
	return (iterator);
}

template< typename T>
T	*MutantStack<T>::end(void)
{
	T	*literator = NULL;

	this->push(2147483647);
	literator = &this->top();
	this->pop();
	return (literator);
}

template< typename T >
MutantStack<T>::iterator::iterator(void) : _iterator(NULL)
{
	std::cout << "(iterator) Defualt constructor is called." << std::endl;
}

template< typename T >
MutantStack<T>::iterator::iterator(T *pointer)
{
	std::cout << "(iterator) Constructor is called." << std::endl;
	this->_iterator = pointer;
}

template< typename T >
MutantStack<T>::iterator::~iterator(void)
{
	// std::cout << "(iterator) Deconstructor is called." << std::endl;
}

template< typename T >
typename MutantStack<T>::iterator	&MutantStack<T>::iterator::operator=(iterator &rhs)
{
	std::cout <<"(iterator> Copy assignment operator is called." << std::endl;
	if (this != &rhs)
		this->_iterator = rhs._iterator;
	return (*this);
}

template< typename T >
bool	MutantStack<T>::iterator::operator!=(iterator &rhs)
{
	return (this->_iterator != rhs._iterator);
}

template< typename T >
bool	MutantStack<T>::iterator::operator==(iterator &rhs)
{
	return (this->_iterator == rhs._iterator);
}

template< typename T >
typename MutantStack<T>::iterator	MutantStack<T>::iterator::operator++(void)
{
	this->_iterator += 1;
	return (MutantStack<T>::iterator(*this));

}

template< typename T >
typename MutantStack<T>::iterator	MutantStack<T>::iterator::operator++(int)
{
	this->_iterator += 1;
	return(*this);
}

template< typename T >
typename MutantStack<T>::iterator	MutantStack<T>::iterator::operator--(void)
{
	this->_iterator -= 1;
	return (MutantStack<T>::iterator(*this));
}

template< typename T>
typename MutantStack<T>::iterator	MutantStack<T>::iterator::operator--(int)
{
	this->_iterator += 1;
	return (*this);
}

template< typename T>
T	MutantStack<T>::iterator::operator*(void)
{
	return(*this->_iterator);
}

template< typename T >
std::ostream	&operator<<(std::ostream &out, MutantStack<T> &rhs)
{
	MutantStack<T>	tmpStack(rhs);

	std::cout << "(MutantStack) size[" << tmpStack.size() << "] top";


	for (; tmpStack.size() > 0; tmpStack.pop())
		std::cout << "[" << tmpStack.top() << "] ";

	return (out);
}
// template< typename T >
// std::ostream	&operator<<(std::ostream &out, typename MutantStack<T>::iterator &rhs);