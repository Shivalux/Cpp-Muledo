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
}
