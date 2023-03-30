/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:41:20 by sharnvon          #+#    #+#             */
/*   Updated: 2023/03/30 03:13:08 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool		dataFomatCheck(std::string line);
static void		convertLineToDataMap(std::string line, std::map<std::string, float> &dataMap);

BitcoinExchange::BitcoinExchange(void) : _isData(false)
{
	// std::cout << "[BitcoinExchange] default constructor is called." << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string fileName) : _fileName(fileName), _isData(false)
{
	std::ifstream	inFile;
	std::string		line;

	// std::cout << "[BitcoinExchange] constructor is called." << std::endl;
	inFile.open(fileName);
	if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			std::getline(inFile, line);
			if (dataFomatCheck(line))
				convertLineToDataMap(line, this->_exchangeDataBase);
		}
		inFile.close();
		this->_isData = true;
	}
	else if (!inFile.is_open())
		std::cout << "Error: count not open data file." << std::endl;
}

BitcoinExchange::~BitcoinExchange(void)
{
	// std::cout << "[BitcoinExchange] desructor is called." << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	// std::cout << "[BitcoinExchange] copy-constructor is called." << std::endl;
	this->_fileName = src._fileName;
	this->_isData = src._isData;
	this->_exchangeDataBase = src._exchangeDataBase;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange &rhs)
{
	// std::cout << "[BitcoinExchange] copy-assignment operator is called." << std::endl;
	if (this != &rhs)
	{
		this->_fileName = rhs._fileName;
		this->_isData = rhs._isData;
		this->_exchangeDataBase = rhs._exchangeDataBase;
	}
	return (*this);
}

float	BitcoinExchange::exchangeValue(std::string date, float value)
{
	std::map<std::string, float>::iterator	it;

	try
	{
		return (this->_exchangeDataBase.at(date) * value);
	}
	catch(const std::exception &exception)
	{
		it = this->_exchangeDataBase.begin();
		for (;it != this->_exchangeDataBase.end(); ++it)
		{
			if (date.compare(it->first) < 0)
				return ((--it)->second * value);
		}
	}
	return ((--it)->second * value);
}

std::string	BitcoinExchange::getFileName(void)
{
	return (this->_fileName);
}

std::map<std::string, float>	BitcoinExchange::getExchangeDataBase(void)
{
	return (this->_exchangeDataBase);
}

bool	BitcoinExchange::isData(void)
{
	return (this->_isData);
}

std::ostream	&operator<<(std::ostream &c, BitcoinExchange &rhs)
{
	std::map<std::string, float>	dataExchange;

	dataExchange = rhs.getExchangeDataBase();
	c << "[ fileName: " << rhs.getFileName() << " ]" << std::endl;
	c << "[exchangeDataBase : (date, value)] " << std::endl;
	for (std::map<std::string, float>::iterator it = dataExchange.begin();
		 it != dataExchange.end(); ++it)
		 c << it->first << "," << it->second << std::endl;
	return (c);
}

static bool	dataFomatCheck(std::string line)
{
	int	index = 0;
	int	dashCount = 0;
	int	periodCount = 0;

	if (line.find(",") == std::string::npos)
		return (false);
	while (line[index] && line[index] != ',')
	{
		if (line[index] == '-')
			dashCount++;
		if ((!isdigit(line[index]) && line[index] != '-')
			|| (line[index] == '-' && index != 4 && index != 7))
			return (false);
		++index;
	}
	if (dashCount != 2 || index != 10 || !line[index])
		return (false);
	++index;
	if (!line[index])
		return (false);
	while (line[index])
	{
		if (line[index] == '.')
			periodCount++;
		if ((!isdigit(line[index]) && line[index] != '.') || periodCount > 1)
			return (false);
		index++;
	}
	return (true);
}

static void convertLineToDataMap(std::string line, std::map<std::string, float> &dataMap)
{
	std::string	date;
	std::string	value;
	int			index;

	index = 0;
	while (line[index] != ',')
		date += line[index++];
	index++;
	while (line[index])
		value += line[index++];
	dataMap[date] = stof(value);
}
