/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:53:24 by sharnvon          #+#    #+#             */
/*   Updated: 2023/03/30 03:43:49 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// static std::string argumentCheck(int argc, char **argv);

int main(int argc, char **argv)
{
	try
	{
		PmergeMe mergeMe(argc, argv);
		std::cout << mergeMe;
	}
	catch(const std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
	
	// std::string	line;

	// line = argumentCheck(argc, argv);
	// if (line == "")
	// 	return (EXIT_FAILURE);
		
	// PmergeMe	merge(line);

	// std::cout << std::fixed << std::setprecision(7);
	// std::cout << "Before:  " << line << std::endl;
	// // std::cout << "After :  ";
	// std::cout << "AfterV:  ";
	// merge.printSortedVector();
	// std::cout << std::endl;
	// std::cout << "AfterL:  ";
	// merge.printSortedList();
	// std::cout << "\nTime to process a range of " << merge.getSizeList() << " elements with std::list   : " << merge.getTimeList() << " seccond." << std::endl;
	// std::cout << "Time to process a range of " << merge.getSizeVector() << " elements with std::vector : " << merge.getTimeVector() << " seccond." << std::endl;
	// return (EXIT_SUCCESS);
}

// static std::string argumentCheck(int argc, char **argv)
// {
// 	std::string	result;

// 	if (argc < 2)
// 	{
// 		std::cout << "PmergeMe: Error: wrong argument.\n(hint) $> ./PmergeMe [positive numbers]" << std::endl;
// 		return ("");
// 	}
// 	for (int i = 1; argv[i]; ++i)
// 	{
// 		for(int j = 0; argv[i][j]; ++j)
// 		{
// 			if (isdigit(argv[i][j]) || argv[i][j] == ' ' && argv[i][j - 1] != ' ')
// 				result += argv[i][j];
// 			else
// 			{
// 				std::cout << "PmergerMe: Error: invalid character in arguments." << std::endl;
// 				return ("");
// 			}
// 		}
// 		result += ' ';
// 	}
// 	return (result);
// }