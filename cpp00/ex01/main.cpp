/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:45:27 by sharnvon          #+#    #+#             */
/*   Updated: 2022/10/29 23:13:18 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstring>
#include <cstdio>
#include <cctype>

static std::string	stringToUpper(std::string str);
static std::string	stringTrimSpace(std::string str);
static void			printErrorCmd(void);
static void 		addContact(PhoneBook *phoneBook);
static void			searchContact(PhoneBook phoneBook);

int	main(void)
{
	std::string	input;
	std::string	index;
	PhoneBook	phoneBook;

	while (!std::cin.eof() && input != "EXIT")
	{
		std::cout << "insert_a_command: ";
		std::getline(std::cin, input);
		input = stringToUpper(input);
		input = stringTrimSpace(input);
		if (!std::cin.eof() && input == "ADD")
			addContact(&phoneBook);
		else if (!std::cin.eof() && input == "SEARCH")
			searchContact(phoneBook);
		else if (!std::cin.eof() && input != "EXIT")
			printErrorCmd();
	}
	std::cout << "the phone book has been destroyed..." << std::endl;
	return (0);
}

static void	searchContact(PhoneBook phoneBook)
{
	int			indexResult;
	std::string	index;

	phoneBook.phoneBookTable();
	std::cout << "insert_index: ";
	std::getline(std::cin, index);
	for (int i = 0; index[i] != '\0'; i++)
	{
		if (!isdigit(index[i]))
		{
			std::cout << "wrong_index_insert" << std::endl;
			return ;
		}
	}
	indexResult = stoi(index);
	if (!std::cin.eof() &&indexResult >= 1 && indexResult <= 8)
		phoneBook.contact[indexResult - 1].cPrint();
	else if (!std::cin.eof())
		std::cout << "wrong_index_insert" << std::endl;
}

static void addContact(PhoneBook *phoneBook)
{
	std::string	input;
	std::string	title[5] = { "first_name", "last_name", "nickname", "phone_number", "darkest_secret"};
	static int	index = 0;
	int			count;

	count = 0;
	std::cout << "---------------------------------------------" << std::endl;
	while (!std::cin.eof() && count < 5)
	{
		std::cout << title[count] << ": ";
		std::getline(std::cin, input);
		if (!std::cin.eof() && stringTrimSpace(input) != "")
		{
			if (count == 0)
				phoneBook->contact[(index % 8)].cAdd(input, FIRST);
			else if (count == 1)
				phoneBook->contact[(index % 8)].cAdd(input, LAST);
			else if (count == 2)
				phoneBook->contact[(index % 8)].cAdd(input, NICK);
			else if (count == 3)
				phoneBook->contact[(index % 8)].cAdd(input, PHONE);
			else if (count == 4)
				phoneBook->contact[(index % 8)].cAdd(input, SECRET);
			count++;
		}
	}
	std::cout << "---------------------------------------------" << std::endl;
	index++;
}

static void	printErrorCmd(void)
{
	std::cout << "---------------------------------------------" << std::endl;;
	std::cout << "incorrect_command\n";
	std::cout << "---------------------------------------------" << std::endl;;
	std::cout << "• ADD      -- save_a_new_contact.\n";
	std::cout << "• SEARCH   -- display_a_specific_contact.\n";
	std::cout << "• EXIT     -- quit_the_program." << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
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

static std::string	stringTrimSpace(std::string str)
{
	std::string	result;
	int			startIndex;
	int			endIndex;

	startIndex = 0;
	endIndex = str.length() - 1;
	while ((str[startIndex] >= 9 && str[startIndex] <= 13) || str[startIndex] == ' ')
		startIndex++;
	if (str[startIndex] == '\0')
		return ("");
	while ((endIndex >=0 && str[endIndex] >= 9 && str[endIndex] <= 13)
		|| (endIndex >= 0 && str[endIndex] == ' '))
		endIndex--;
	while (startIndex <= endIndex)
		result = result + str[startIndex++];
	return (result);
}
