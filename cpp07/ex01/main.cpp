/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:52:19 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/28 07:43:18 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"
#include <ctime>

class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void	printer(T const &x)
{
	std::cout << "[" << x << "]";
}

int main(void)
{
	srand(time(NULL));
	int			size = 10;
	int 		tabInt[size];
	char		tabChar[size];
	float		tabFloat[size];
	double		tabDouble[size];
	std::string tabString[] = {"hello0", "hello1", "hello2", "hello3", "hello4", "hello5", "hello6", "hello7", "hello8", "hello9"};
	Awesome 	tabAwesom[size];

	for (int i = 0; i < size; i++)
	{
		tabInt[i] = rand() % 101;
		tabChar[i] =  ' ' + (rand() % 95);
		tabFloat[i] = static_cast<float>(rand()) / RAND_MAX;
		tabDouble[i] = static_cast<double>(rand()) / RAND_MAX + 42;
	}
	std::cout << "(line:53) tabInt -----> ";
	iter(tabInt, size, printer<int>);
	std::cout << std::endl;
	std::cout << "(line:56) tabChar ----> ";
	iter(tabChar, size, printer<char>);
	std::cout << std::endl;
	std::cout << "(line:59) tabFloat ---> ";
	iter(tabFloat, size, printer<float>);
	std::cout << std::endl;
	std::cout << "(line:62) tabDouble --> ";
	iter(tabDouble, size, printer<double>);
	std::cout << std::endl;
	std::cout << "(line:65) tabSting ---> ";
	iter(tabString, 10, printer<std::string>);
	std::cout << std::endl;
	std::cout << "(line:68) tabAwesom --> ";
	iter(tabAwesom, size, printer<Awesome>);
	std::cout << std::endl;
	return 0;
}