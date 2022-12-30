/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:32:40 by sharnvon          #+#    #+#             */
/*   Updated: 2022/11/03 19:14:45 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

static std::string	fileReplace(std::string, char *str1, char *str2);
static std::string	readInfile(std::string name);
static void			argurmentCheck(int argc);
static void			outfileCheck(std::ofstream &outfile);


int	main(int argc, char **argv)
{
	std::string		name;
	std::string		file;

	argurmentCheck(argc);
	name = argv[1];
	file = readInfile(name);
	file = fileReplace(file, argv[2], argv[3]);
	name += ".replace";
	std::ofstream	outfile(name);
	outfileCheck(outfile);
	outfile << file << std::endl;
	outfile.close();
	return (EXIT_SUCCESS);
}

static void	argurmentCheck(int argc)
{
	if (argc != 4)
	{
		std::cout << "error: wrong arguments" << std::endl;
		std::cout << "(hint) ./Sed_is_for_losers [filename] [string_to_replace] [string_that_replace_with]" << std::endl;
		exit(EXIT_FAILURE);
	}
}

static std::string	readInfile(std::string name)
{
	std::ifstream	infile(name);
	std::string		buff;
	std::string		file;

	if (!infile)
	{
		std::cout << "error: file connot open, please check" << std::endl;
		exit(EXIT_FAILURE);
	}
	while (1 > 0)
	{
		std::getline(infile, buff);
		if (infile.eof())
			break ;
		if (file.empty())
			file = buff;
		else
			file += '\n' + buff;
	}
	infile.close();
	return (file);
}

static void	outfileCheck(std::ofstream &outfile)
{
	if (!outfile)
	{
		std::cout << "error: i cannot provide outfile for u, sorry" << std::endl;
		exit(EXIT_FAILURE);
	}
}

static std::string	fileReplace(std::string file, char *str1, char *str2)
{
	std::string	result;
	int			index = 0;
	int			len;

	len = strlen(str1);
	while (file[index] != '\0')
	{
		if (file[index] == str1[0] && (int)file.find(str1, index) == index)
		{
			result += str2;
			index += len;
		}
		else
		{
			result += file[index];
			index++;
		}
	}
	return (result);
}