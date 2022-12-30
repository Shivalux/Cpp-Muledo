/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 02:41:07 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/27 19:36:42 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void);
void	identify(Base *pointer);
void	identify(Base &pointer);

int	main(void)
{
	Base	*pointer;

	pointer = generate();
	identify(pointer);
	identify(*pointer);
	try
	{
		delete pointer;
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	return (0);
}

Base	*generate(void)
{
	int	choice;

	srand(time(NULL));
	choice = rand();
	std::cout << "(generate) ------------------> ";
	if (choice % 3 == 0)
	{
		std::cout << "[class A]" << std::endl;
		return (new A);
	}
	else if (choice % 3 == 1)
	{
		std::cout << "[class B]" << std::endl;
		return (new B);
	}
	else
	{
		std::cout << "[class C]" << std::endl;
		return (new C);
	}
}

void	identify(Base *pointer)
{
	A	*a;
	B	*b;
	C	*c;

	std::cout << "(identify *) ----------------> ";
	a = dynamic_cast<A*>(pointer);
	if (a != NULL)
	{
		std::cout << "[class A]" << std::endl;
		return ;
	}
	b = dynamic_cast<B*>(pointer);
	if (b != NULL)
	{
		std::cout << "[class B]" << std::endl;
		return ;
	}
	c = dynamic_cast<C*>(pointer);
	if (c != NULL)
	{
		std::cout << "[class C]" << std::endl;
		return ;
	}
}

void	identify(Base &pointer)
{
	std::cout << "(identify &) ----------------> ";
	try
	{
		A	&a = dynamic_cast<A&>(pointer);
		std::cout << "[class A]" << std::endl;
		(void)a;
	}
	catch(const std::bad_cast &exception){};
	try
	{
		B	&a = dynamic_cast<B&>(pointer);
		std::cout << "[class B]" << std::endl;
		(void)a;
	}
	catch(const std::bad_cast &exception){};
	try
	{
		C	&a = dynamic_cast<C&>(pointer);
		std::cout << "[class C]" << std::endl;
		(void)a;
	}
	catch(const std::bad_cast &exception){};
}