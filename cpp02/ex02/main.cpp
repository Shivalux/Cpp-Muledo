/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:19:25 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/12 21:58:51 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << "a:   " << a << "\t\t\t\t\tline 20" <<std::endl;
	std::cout << "++a: " << ++a << "\t\t\t\tline 21" << std::endl;
	std::cout << "a  : " << a << "\t\t\t\tline 22" << std::endl;
	std::cout << "a++: " << a++ << "\t\t\t\tline 23" << std::endl;
	std::cout << "a  : " << a << "\t\t\t\tline 24\n" << std::endl;

	std::cout << "b  : " << b << "\t\t\t\tline 26\n" <<  std::endl;

	std::cout << "max(" << a << ", " << b << ") = " << Fixed::max(a,b) << std::endl;
	std::cout << "min(" << a << ", " << b << ") = " << Fixed::min(a,b) << std::endl;
	std::cout << "min(" << a << ", " << a << ") = " << Fixed::min(a,a) << std::endl;

	std::cout << "\nbool of (" << a << " == " << b << ") = " << (a == b) << std::endl;
	std::cout << "bool of (" << a << " != " << b << ") = " << (a != b) << std::endl;
	std::cout << "bool of (" << b << " == " << b << ") = " << (a == a) << std::endl;
	
	return (0);
}