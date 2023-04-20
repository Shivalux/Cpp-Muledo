/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:25:08 by sharnvon          #+#    #+#             */
/*   Updated: 2023/03/28 11:41:31 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <cstring>

static bool	argumentCheck(int argc, char **argv);
static bool	inputFomatCheck(std::string line);
static bool	getDateValue(std::string line, std::string &date, float *value);
static int	getDayofMonth(int month, int year);

int	main(int argc, char **argv)
{
	std::ifstream	inputFile;
	std::string		line;
	std::string		date;
	float			value;
	int				firstLine = 0;

	if (!argumentCheck(argc, argv))
		return (EXIT_FAILURE);
	BitcoinExchange	exchange("data.csv");
	if (!exchange.isData())
		return (EXIT_FAILURE);
	inputFile.open(argv[1]);
	if (!inputFile.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE);
	}
	while (!inputFile.eof())
	{
		std::getline(inputFile, line);
		if (line == "" || (!firstLine++ && !line.compare("date | value")))
			continue ;
		else if (!inputFomatCheck(line))
			std::cout << "Error: bad input => " << line << std::endl;
		else if (getDateValue(line, date, &value))
				std::cout << date << " => " << value << " = " << exchange.exchangeValue(date, value) << std::endl;
	}
	inputFile.close();
	return (EXIT_SUCCESS);
}

static bool	argumentCheck(int argc, char **argv)
{
	char *fileType;

	if (argc != 2)
	{
		std::cout << "Error: wrong argument.\n(hint) $> ./btc [file_name.txt]" << std::endl;
		return (false);
	}
	// fileType = strrchr(argv[1], '.');
	// if (!fileType && strncmp(fileType, ".txt", 5))
	// {
	// 	std::cout << "Error: invalid file type.\n(hint) file type must be \".txt\"." << std::endl;
	// 	return (false);
	// }
	return (true);
}

static bool	inputFomatCheck(std::string line)
{
	int			index = 0;
	int			dashCount = 0;
	int			periodCount = 0;
	std::string	date;

	while (line[index] && line[index] != '|')
	{
		if (line[index] == '-')
			++dashCount;
		if ((!isdigit(line[index]) && line[index] != '-' && line[index] != ' ')
			|| (line[index] == '-' && index != 4 && index != 7)
			|| (dashCount > 2))
			return (false);
		++index;
	}
	if ((dashCount != 2 || index != 11 || !line[index] || !line[index + 2])
		|| (line[index - 1] != ' ' || line[index + 1] != ' '))
		return (false);
	index += 2;
	if (line[index] == '-')
		++index;
	while (line[index])
	{
		if (line[index] == '.')
			++periodCount;
		if ((!isdigit(line[index]) && line[index] != '.')
			|| periodCount > 1)
			return (false);
		++index;
	}
	return (true);
}

static bool	getDateValue(std::string line, std::string &date, float *value)
{
	std::string stringValue;
	int			index = 0;
	int			valid = true;
	int			month;
	int			day;

	date = "";
	while (line[index] && line[index] != ' ')
		date += line[index++];
	index += 3;
	while (line[index])
		stringValue += line[index++];
	*value = stof(stringValue);
	month = stoi(date.substr(5, 2));
	day = stoi(date.substr(8, 2));
	if (month > 12 && valid--)
		std::cout << "Error: invaid month." << std::endl;
	else if (day > getDayofMonth(month, stoi(date.substr(0, 4))) && valid--)
		std::cout << "Error: invalid day of the month." << std::endl;
	else if (*value < 0.0f && valid--)
		std::cout << "Error: not a positive number." << std::endl;
	else if (*value > 1000.0f && valid--)
		std::cout << "Error: too large a number." << std::endl;
	if (!valid)
		return (false);
	return (true);
}

static int	getDayofMonth(int month, int year)
{
	int		day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool	isLeap;

	isLeap = false;
	if (year % 4 == 0)
	{
		if (year % 100 != 0 || year % 400 == 0)
			isLeap = true;
	}
	if (isLeap && month == 2)
		return (29);
	return (day[month - 1]);
}