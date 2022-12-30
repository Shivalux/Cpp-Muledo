/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:13:58 by sharnvon          #+#    #+#             */
/*   Updated: 2022/10/27 23:20:15 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cctype>

static std::string	stringToUpper(std::string str);
static std::string stringJoin(std::string str1, std::string str2);
static std::string stringTrimWhiteSpace(std::string str);

int	main(int argc, char **argv)
{
	std::string	result;
	std::string	temp;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; argv[i] != NULL; i++)
	{
		temp = stringToUpper(argv[i]);
		temp = stringTrimWhiteSpace(temp);
		result = stringJoin(result, temp);
	}
	std::cout << result << std::endl;
	return (0);
}

static std::string	stringToUpper(std::string str)
{
	std::string	result;
	char		character;

	for (int i = 0; str[i] != '\0'; i++)
	{
		character = toupper(str[i]);
		result = result + character;
	}
	return (result);
}

static std::string	stringTrimWhiteSpace(std::string str)
{
	std::string	result;
	int			startIndex;
	int			endIndex;

	startIndex = 0;
	endIndex = str.length() - 1;
	while ((str[startIndex] >= 9 && str[startIndex] <= 13) || str[startIndex] == ' ')
		startIndex++;
	while ((endIndex != -1 && str[endIndex] >= 9 && str[endIndex] <= 13) 
		|| (endIndex != -1 && str[endIndex] == ' '))
		endIndex--;
	while (startIndex <= endIndex)
		result = result + str[startIndex++];
	return (result);
}

static std::string	stringJoin(std::string str1, std::string str2)
{
	std::string	result;

	if (str1.empty())
		result = str2;
	else
		result = str1 + " " + str2;
	return (result);
}
