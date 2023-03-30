/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:02:06 by sharnvon          #+#    #+#             */
/*   Updated: 2023/03/30 11:33:06 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <unistd.h>
#include <cstdio>

static void			mergeSortV(std::vector<int> &container, int begin, int end);
static void			mergeV(std::vector<int> &container, int begin, int mid, int end);
static void			mergeSortByVector(std::string numbers, float *timeUse, int *size, std::vector<int> &containerV);
static void			mergeSortByList(std::string numbers, float *timeUse, int *size, std::list<int> &containerL);
static void			mergeSortList(std::list<int> &container);
static std::string	argumentCheck(int argc, char **argv);

PmergeMe::PmergeMe(void) : _timeList(0.0f), _timeVector(0.0f)
{
	// std::cout << "[PmergeMe] default constructor is called." << std::endl;
}

PmergeMe::PmergeMe(std::string numbers) : _numbers(numbers), _timeList(0.0f), _timeVector(0.0f)
{
	// std::cout << "[PmergeMe] constructor is called." << std::endl;
	mergeSortByVector(this->_numbers, &this->_timeVector, &this->_sizeVector, this->_sortedVector);
	mergeSortByList(this->_numbers, &this->_timeList, &this->_sizeList, this->_sortedList);
}

PmergeMe::PmergeMe(int argc, char **argv) :  _timeList(0.0f), _timeVector(0.0f)
{
	// std::cout << "[PmergeMe] constructor is called." << std::endl;
	this->_numbers = argumentCheck(argc, argv);
	mergeSortByVector(this->_numbers, &this->_timeVector, &this->_sizeVector, this->_sortedVector);
	mergeSortByList(this->_numbers, &this->_timeList, &this->_sizeList, this->_sortedList);
}

PmergeMe::~PmergeMe(void)
{
	// std::cout << "[PmergeMe] destructor is called." << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	// std::cout << "[PmergeMe] copy-constructor is called." << std::endl;
	this->_numbers = src._numbers;
	this->_timeList = src._timeList;
	this->_timeVector = src._timeVector;
	this->_sizeList = src._sizeList;
	this->_sizeVector = src._sizeVector;
	this->_sortedList = src._sortedList;
	this->_sortedVector = src._sortedVector;
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &rhs)
{
	// std::cout << "[PmergeMe] copy_assignment operator is called." <<std::endl;
	if(this != &rhs)
	{
		this->_numbers = rhs._numbers;
		this->_timeList = rhs._timeList;
		this->_timeVector = rhs._timeVector;
		this->_sizeList = rhs._sizeList;
		this->_sizeVector = rhs._sizeVector;
		this->_sortedList = rhs._sortedList;
		this->_sortedVector = rhs._sortedVector;
	}
	return (*this);
}

std::string	PmergeMe::getNumbers(void)
{
	return(this->_numbers);
}

float	PmergeMe::getTimeList(void)
{
	return (this->_timeList);
}

float	PmergeMe::getTimeVector(void)
{
	return (this->_timeVector);
}

int	PmergeMe::getSizeList(void)
{
	return (this->_sizeList);
}

int	PmergeMe::getSizeVector(void)
{
	return (this->_sizeVector);
}

void	PmergeMe::printSortedVector(void)
{
	for (int i = 0; i < static_cast<int>(this->_sortedVector.size()); ++i)
		std::cout << this->_sortedVector[i] << " ";
}

void	PmergeMe::printSortedList(void)
{
	std::list<int>::iterator	it;

	for (it = this->_sortedList.begin(); it != this->_sortedList.end(); ++it)
		std::cout << *it << " ";
}

std::ostream	&operator<<(std::ostream &c, PmergeMe &rhs)
{
	std::cout << std::fixed << std::setprecision(7);
	std::cout << "Before:  " << rhs.getNumbers() << std::endl;
	std::cout << "AfterV :  ";
	rhs.printSortedVector();
	std::cout << "\nAfterL :  ";
	rhs.printSortedVector();
	std::cout << "\nTime to process a range of " << rhs.getSizeList();
	std::cout << " elements with std::list   : " << rhs.getTimeList() << " seccond." << std::endl;
	std::cout << "Time to process a range of " << rhs.getSizeVector();
	std::cout << " elements with std::vector : " << rhs.getTimeVector() << " seccond." << std::endl;
	return (c);
}

static std::string	argumentCheck(int argc, char **argv)
{
	std::string	result;

	if (argc < 2)
		throw (PmergeMe::WrongArgument());
	for (int i = 1; argv[i]; ++i)
	{
		for(int j = 0; argv[i][j]; ++j)
		{
			if (isdigit(argv[i][j]) || (argv[i][j] == ' ' && argv[i][j - 1] != ' '))
				result += argv[i][j];
			else
				throw (PmergeMe::WrongCharacter());
		}
		result += ' ';
	}
	return (result);
}

static void	mergeSortByVector(std::string numbers, float *timeUse, int *size, std::vector<int> &containerV)
{
	std::vector<int>	container;
	std::string			number;
	clock_t				timer;
	int					count = 0;

	timer = clock();
	for (int i = 0; numbers[i]; ++i)
	{
		if (isdigit(numbers[i]))
			number += numbers[i];
		else
		{
			container.push_back(stoi(number));
			number = "";
			count++;
		}
	}
	mergeSortV(container, 0, count - 1);
	*timeUse = static_cast<float>(clock() - timer) / CLOCKS_PER_SEC;
	*size = count;
	containerV = container;
}

static void	mergeSortV(std::vector<int> &container, int begin, int end)
{
	int	mid;

	if (begin < end)
	{
		mid = (begin + end) / 2;
		mergeSortV(container, begin, mid);
		mergeSortV(container, mid + 1, end);
		mergeV(container, begin, mid, end);
	}
}

static void	mergeV(std::vector<int> &container, int begin, int mid, int end)
{
	std::vector<int>	result;
	int					count1;
	int					count2;

	count1 = begin;
	count2 = mid + 1;
	while (count1 <= mid && count2 <= end)
	{
		if (container[count1] <= container[count2])
			result.push_back(container[count1++]);
		else
			result.push_back(container[count2++]);
	}
	while (count1 <= mid)
		result.push_back(container[count1++]);
	while (count2 <= end)
		result.push_back(container[count2++]);
	for (int i = begin, j = 0; j < static_cast<int>(result.size()); ++i, ++j)
		container[i] = result[j];
}

static void	mergeSortByList(std::string numbers, float *timeUse, int *size, std::list<int> &containerL)
{
	std::list<int>	container;
	clock_t			timer;
	int				count = 0;
	std::string		number;

	timer = clock();
	for (int i = 0; numbers[i]; ++i)
	{
		if (isdigit(numbers[i]))
			number += numbers[i];
		else
		{
			container.push_back(stoi(number));
			count++;
			number = "";
		}
	}
	mergeSortList(container);
	*timeUse = static_cast<float>(clock() - timer) / CLOCKS_PER_SEC;
	*size = count;
	containerL = container;
}

static void	mergeSortList(std::list<int> &container)
{
	int							mid;
	int							length;
	std::list<int>				leftSide;
	std::list<int>				rightSide;
	std::list<int>::iterator	it;

	length = container.size();
	if (length <= 1)
		return ;
	it = container.begin();
	mid = length / 2;
	for (int i = 0; i < length; i++, it++)
	{
		if (i < mid)
			leftSide.push_back(*it);
		else
			rightSide.push_back(*it);
	}
	mergeSortList(leftSide);
	mergeSortList(rightSide);
	leftSide.merge(rightSide);
	container = leftSide;
}

// static void	mergeSortList(std::list<int> &container, int begin, int end);
// static void	mergeL(std::list<int> &container, int begin, int mid, int end);

// static void	mergeSortByList(std::string numbers, float *timeUse, int *size, std::list<int> &containerL)
// {
// 	std::list<int>	container;
// 	clock_t			timer;
// 	int				count = 0;
// 	std::string		number;

// 	timer = clock();
// 	for (int i = 0; numbers[i]; ++i)
// 	{
// 		if (isdigit(numbers[i]))
// 			number += numbers[i];
// 		else
// 		{
// 			container.push_back(stoi(number));
// 			count++;
// 			number = "";
// 		}
// 	}
// 	mergeSortList(container, 0, count - 1);
// 	*timeUse = static_cast<float>(clock() - timer) / CLOCKS_PER_SEC;
// 	*size = count;
// 	containerL = container;
// }

// static void	mergeSortList(std::list<int> &container, int begin, int end)
// {
// 	int	mid;

// 	if (begin < end)
// 	{
// 		mid = (begin + end) / 2;
// 		mergeSortList(container, begin, mid);
// 		mergeSortList(container, mid + 1, end);
// 		mergeL(container, begin, mid, end);
// 	}
// }

// static void	mergeL(std::list<int> &container, int begin, int mid, int end)
// {
// 	std::list<int>				result;
// 	std::list<int>::iterator	itmid;
// 	std::list<int>::iterator	it1 = container.begin();
// 	std::list<int>::iterator	it2 = container.begin();
// 	std::list<int>::iterator	itend = container.begin();

// 	for (int i = 0; i < begin; ++i, ++it1);
// 	for (int i = 0; i < mid + 1; ++i, ++it2);
// 	itmid = it2;
// 	for(int i = 0; i < end + 1; ++i, ++itend);
// 	while (it1 != itmid && it2 != itend)
// 	{
// 		if (*it1 <= *it2)
// 			result.push_back(*(it1)++);
// 		else
// 			result.push_back(*(it2)++);
// 	}
// 	for (;it1 != itmid; ++it1)
// 		result.push_back(*it1);
// 	for (;it2 != itend; ++it2)
// 		result.push_back(*it2);
// 	it1 = container.begin();
// 	for (int i = 0; i < begin; ++i, ++it1);
// 	it2 = result.begin();
// 	for (int i = 0; i < result.size(); ++it1, ++it2, ++i)
// 		*it1 = *it2;
// }
