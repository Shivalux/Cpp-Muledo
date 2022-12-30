/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:12:39 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/30 23:59:30 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <vector>
#include <stack>
#include <iostream>
#include <ctime>

template < typename T >
void	printValue(T &container)
{
	typename T::iterator	itBegin = container.begin();
	typename T::iterator	itEnd = container.end();

	std::cout << "size[" << container.size() << "]";
	if (container.size() >= 1)
	{
		std::cout << " top";
		for (;itBegin != --itEnd;)
			std::cout << "[" << *itEnd  << "] ";
		std::cout << "[" << *itBegin  << "]";
	}
	std::cout << std::endl;
}

int main(void)
{
	srand(time(NULL));
	MutantStack<int>	mStackInt;
	std::list<int>		listInt;
	std::vector<int>	vectorInt;
	int					size = 10;

	std::cout << "================= Top(lastValue)/push()-Test =================" << std::endl;
	for (int i = 0, value = 0; i < 4; i++)
	{
		value = (rand() % 90) + 10;
		mStackInt.push(value);
		listInt.push_back(value);
		vectorInt.push_back(value);
	}
	std::cout << "(line:53) " << mStackInt << std::endl;
	std::cout << "(line:54) mStackInt.top() ---> " << mStackInt.top() << std::endl;
	std::cout << "(line:55) listInt.back() ----> " << listInt.back() << std::endl;
	std::cout << "(line:56) vectorInt.back() --> " << vectorInt.back() << std::endl;
	std::cout << "================= Size/pop()-Test =================" << std::endl;
	std::cout << "(line:58) pop [" << mStackInt.top() << "]" << std::endl;
	mStackInt.pop();
	listInt.pop_back();
	vectorInt.pop_back();
	std::cout << "(line:62) mStackInt.size() --> " << mStackInt.size() << std::endl;
	std::cout << "(line:63) listInt.size() ----> " << listInt.size() << std::endl;
	std::cout << "(line:64) vectorInt.size() --> " << vectorInt.size() << std::endl;
	for (int i = 0, value; i < size; i++)
	{
		value = (rand() % 90) + 10;
		mStackInt.push(value);
		listInt.push_back(value);
		vectorInt.push_back(value);
	}
	std::cout << "================= Iterator-Test =================" << std::endl;
	MutantStack<int>::iterator	itBStack = mStackInt.begin();
	MutantStack<int>::iterator	itEStack = mStackInt.end();
	std::list<int>::iterator	itBList	= listInt.begin();
	std::vector<int>::iterator	itBVector	= vectorInt.begin();
	++itBStack;
	--itBStack;
	while (itBStack != itEStack)
	{
		std::cout << "[" << *itBStack << "]";
		std::cout << "--[" << *itBList << "]--";
		std::cout << "[" << *itBVector << "]" << std::endl;
		itBList++;
		itBVector++;
		itBStack++;
	}
	std::cout << "(line:88) int " << mStackInt << std::endl;
	std::cout << "(line:90)  listInt   (list) ";
	printValue(listInt);
	std::cout << "(line:92) vactorInt (vector)";
	printValue(listInt);
	std::cout << "================= CopyOperator/CopyAssignment Test =================" << std::endl;
	std::stack<int>		s(mStackInt);
	MutantStack<int>	copyConsturtor(mStackInt);
	MutantStack<int>	copyAssign;
	std::cout << "(line:97) copyAssign     " << copyAssign << std::endl;
	copyAssign = mStackInt;
	std::cout << "(line:99) mStackInt      " << copyAssign << std::endl;
	std::cout << "(line:100) copyAssign     " << copyAssign << std::endl;
	std::cout << "(line:101) copyConstrutor " << copyAssign << std::endl;
	return (0);
}