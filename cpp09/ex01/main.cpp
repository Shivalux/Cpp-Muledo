/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:22:01 by sharnvon          #+#    #+#             */
/*   Updated: 2023/03/30 23:07:21 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	try
	{
		RPN	invertedPolishMarthematicalExpression(argc, argv);
		std::cout << invertedPolishMarthematicalExpression.getResult() << std::endl;
	}
	catch(const std::exception &exeption)
	{
		std::cout << exeption.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
