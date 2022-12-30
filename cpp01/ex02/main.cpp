/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:57:49 by sharnvon          #+#    #+#             */
/*   Updated: 2022/10/31 22:33:29 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string	variable = "HI THIS IS BRAIN";
	std::string *stringPTR = &variable;
	std::string	&stringREF = variable;

	std::cout << "• the memory address of the string variable: " <<  &variable << std::endl;
	std::cout << "• the memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "• the memory address held by stringREF: " << &stringREF << std::endl;
	std::cout << "• the value of the string variable: " << variable << std::endl;
	std::cout << "• the value of pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "• the value of pointed to by stringREF: " << stringREF << std::endl;
	return (EXIT_SUCCESS);
}