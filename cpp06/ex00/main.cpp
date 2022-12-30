/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:57:24 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/26 20:52:42 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>
#include <cmath>
#include <cstring>
#include <exception>
#include <iomanip>
#include <limits.h>

std::string	argumentCheck(int argc, char *argument);
bool		isSpecialArgument(std::string argument);
void		setPrecision(std::string value);
void		printResult(long double value);

int main(int argc, char **argv)
{
	std::string	string;
	long double value;

	string = argumentCheck(argc, argv[1]);
	if (string == "")
	{
		std::cout << "ERROR: (hint) $>./convert [decimal_number/inf/nan] " << std::endl;
		return (1);
	}
	value = stold(string);
	setPrecision(string);
	printResult(value);
	return (0);
}

// function check argument
// correct   --> return string
// incorrect --> return ""
std::string	argumentCheck(int argc, char *argument)
{
	std::string	result;
	int			index = 0;
	int			precision = 0;
	int			fCharacter = 0;

	if (argc != 2 || argument == NULL)
		return ("");
	result = std::string(argument);
	for (int i = 0; result[i] != '\0'; i++)
		result[i] = tolower(result[i]);
	if (isSpecialArgument(result))
		return (result);
	if (result[index] == '-')
		index++;
	while (result[index] != '\0')
	{
		if (result[index] == 'f')
			fCharacter++;
		else if (result[index] == '.')
		{
			precision++;
			if (!isdigit(result[index + 1]))
				return ("");
		}
		else if (!isdigit(result[index]))
			return ("");
		index++;
	}
	if (precision > 1 || fCharacter > 1 || (fCharacter == 1 && result[index - 1] != 'f'))
		return ("");
	return (result);
}

//	fucntion cheack that is argurment spacial
//	nan/nanf/infinity --> return 1
//	else			  --> return 0
bool	isSpecialArgument(std::string argument)
{
	if (!argument.compare("nan") || !argument.compare("nanf")
		|| !argument.compare("infinity") || !argument.compare("+infinity") || !argument.compare("-infinity")
		|| !argument.compare("inf") || !argument.compare("+inf") || !argument.compare("-inf")
		|| !argument.compare("inff") || !argument.compare("+inff") || !argument.compare("-inff"))
		return (1);
	return (0);
}

// function count precition for setpercision printing
void	setPrecision(std::string value)
{
	int	count = 0;

	for (int i = 0; value[i] != '\0'; i++)
	{
		if (value[i] == '.')
		{
			i++;
			for (int j = 0; value[j + i] != '\0' && value[i +j] != 'f'; j++)
				count++;
			break ;
		}
	}
	if (count == 0)
		count++;
	std::cout << std::fixed << std::setprecision(count);
}

// function print the result onto the screen
void	printResult(long double value)
{
	if (value <= std::numeric_limits<char>::max() && value >= std::numeric_limits<char>::min())
	{
		if (isprint(static_cast<char>(value)))
			std::cout << "[char]   : '" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "[char]   : Non-printable" << std::endl;
	}
	else
		std::cout << "[char]   : Impossible" << std::endl;
	if (value <= std::numeric_limits<int>::max() && value >= std::numeric_limits<int>::min())
		std::cout << "[int]    : " << static_cast<int>(value) << std::endl;
	else
		std::cout << "[int]    : Impossible" << std::endl;
	if ((value <= std::numeric_limits<float>::max() && value >= std::numeric_limits<float>::lowest()) || isinf(value) || isnan(value))
			std::cout << "[float]  : " << static_cast<float>(value) << "f" << std::endl;
	else
		std::cout << "[float]  : Impossible" << std::endl;
	if ((value <= std::numeric_limits<double>::max() && value >= std::numeric_limits<double>::lowest()) || isinf(value) || isnan(value))
			std::cout << "[double] : " << static_cast<double>(value) << std::endl;
	else
		std::cout << "[double] : Impossible" << std::endl;
}