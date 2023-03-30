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

// static bool	argumentCheck(int argc, char **argv, std::deque<char> &container);

int main(int argc, char **argv)
{
	// std::deque<char>	container;
	// int					result;

	try
	{
		RPN	invertedPolishMarthematicalExpression(argc, argv);
		std::cout << invertedPolishMarthematicalExpression << std::endl;
		std::cout << invertedPolishMarthematicalExpression.getResult() << std::endl;
	}
	catch(const std::exception &exeption)
	{
		std::cout << exeption.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
	
	// ifouttCheck(argc, argv, contaistd::endl)
	// {
	// 	std::cout << "RPN: Error: wrong arguments." << std::endl;
	// 	return (EXIT_FAILURE);
	// }
	// for (int i = 0; i < container.size(); ++i)
	// 	std::cout << container[i];
	// std::cout << std::endl;
	// result = container[0] - '0';
	// for (int i = 1; container[i]; ++i)
	// {
	// 	if (container[i] == '+')
	// 		result += container[++i] - '0';
	// 	else if (container[i] == '-')
	// 		result -= container[++i] - '0';
	// 	else if (container[i] == '*')
	// 		result *= container[++i] - '0';
	// 	else if (container[i] == '/')
	// 		result /= container[++i] - '0';
	// }
	// std::cout << "result: " << result << std::endl;
	return (EXIT_SUCCESS);
}

// static bool	argumentCheck(int argc, char **argv, std::deque<char> &container)
// {
// 	int	countOperator;
// 	int	countDigit;
// 	int	check = 0;
// 	int position;

// 	countOperator = 0;
// 	countDigit = 0;
// 	if (argc != 2) // RPN::InvalidArguments::throw();
// 		return (false);
// 	for (int i = 0; i < argv[1][i]; i++)
// 	{
// 		if (isdigit(argv[1][i]))
// 		{
// 			container.push_back(argv[1][i]);
// 			container.push_back('\0');
// 			countDigit++;
// 			check++;
// 		}
// 		else if (strchr("+-*/", argv[1][i]) && container.size())
// 		{
// 			position = container.size() - 2;
// 			for (;position >= 0 && container[position]; --position);
// 			if (position < 0)
// 				return (false); // RPN::InvalidFomatArgument::throw();
// 			else
// 				container[position] = argv[1][i];
// 			countOperator++;
// 			check++;
// 		}
// 		else if (argv[1][i] == ' ')
// 		 {
// 			if (check > 1)
// 				return (false); // RPN::InvalidFomatArgument::throw();
// 			check = 0;
// 		 }
// 		 else
// 		 	return (false); // RPN::InvalidFomatArgument::throw();
// 	}
// 	if (countDigit < 2 || countOperator < 1 || countDigit != countOperator + 1)
// 		return (false); // RPN::InvalidFomatArgument::throw();
// 	return (true);
// }

