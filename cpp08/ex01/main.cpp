/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 22:53:02 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/30 11:09:26 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Span.hpp"

int main(void)
{
	srand(time(NULL));
	unsigned int				size = 10;
	unsigned int				addSize = (size / 2) - 2;
	Span						emptySp;
	Span						sp = Span(size);
	Span						spRange(size);
	std::list<int>				listInt;
	std::list<int>::iterator	head;
	std::list<int>::iterator	end;
	
	for (unsigned int i = 0; i < size; i++)
		sp.addNumber(rand() % 100);
	std::cout << "\n(line:31) [sp]" << sp << std::endl;  // * conment test 100000
	std::cout << "============== ShortestSpan/LongestSpan ==============" <<std::endl;
	std::cout << "(line:33) the shortestSpan --> [" << sp.shortestSpan() << "]" << std::endl;
	std::cout << "(line:34) the longestSapn ---> [" << sp.longestSpan() << "]" << std::endl;
	std::cout << "============== ERROR ==============" <<std::endl;
	try
	{
		std::cout << "(line:38) try to add more than maximum of N...." << std::endl;
		sp.addNumber(rand());
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	try
	{
		std::cout << "(line:48) try shortestSpan() with N = 0" << std::endl;
		emptySp.shortestSpan();
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	try
	{
		std::cout << "(line:57) try longestSpan() with N = 0" << std::endl;
		emptySp.longestSpan();
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	std::cout << "============== CopyConstructor/CopyAssignmentOperator ==============" <<std::endl;
	Span	copySp(sp);
	emptySp = sp;
	std::cout << "(line:66) [   sp   ]" << sp << std::endl;			// * conment test 100000
	std::cout << "(line:67) [ emptySp]" << emptySp << std::endl;	// * conment test 100000
	std::cout << "(line:68) [ copySp ]" << copySp << std::endl;		// * conment test 100000
	std::cout << "============== AddNumberRange ==============" <<std::endl;
	for (unsigned int i = 0; i < size / 2; i++)
		spRange.addNumber(rand() % 100);
	std::cout << "(line:72) [      spRange      ] " << spRange << std::endl;	// * conment test 100000
	std::cout << "(line:73) addRagne of [listINt] to [spRange] -> ";			// * conment test 100000
	for (unsigned int i = 0; i < addSize; i++)
	{
		listInt.push_back(rand() % 100);
		std::cout << "[" << listInt.back() << "] "; // * conment test 100000
	}
	std::cout << std::endl; // * conment test 100000
	head = listInt.begin();
	end = listInt.end();
	end = listInt.end();
	spRange.addNumberRange(head, end);
	std::cout << "(line:84) [spRange] ->" << spRange << std::endl << std::endl;	// * conment test 100000
	return (0);
}