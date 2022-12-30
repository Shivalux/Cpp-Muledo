/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:49:23 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/28 02:06:16 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <ctime>

class Awesome
{
	public:
		Awesome(void) : _n(0) {}
		Awesome( int n ) : _n( n ) {}
		Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
		bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
		int get_n() const { return _n; }
	private:
		int _n;
};

std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int main(void)
{
	srand(time(NULL));
	char		charA = 32 + rand() % 95, charB = 32 + rand() % 95;
	int			intA = rand() % 10000, intB = rand() % 10000;
	float		floatA = static_cast<float>(rand()) / RAND_MAX, floatB = static_cast<float>(rand()) / RAND_MAX;
	double		doubleA = static_cast<double>(rand()) /RAND_MAX, doubleB = static_cast<double>(rand()) / RAND_MAX;
	std::string	stringAr[] = {"hello1", "hello2", "hello3", "hello4", "hello5", "hello6", "hello7", "hello8", "hello9", "hello0"};
	Awesome 	awesomA(rand() % 42), awesomB(rand() % 42);
	int			i = rand() % 10,ii = rand() % 10;
	
	std::cout << "============= char =============" << std::endl;
	std::cout << "(line:48) charA[" << charA << "]  charB[" << charB << "]" << std::endl;
	std::cout << "(line:50) swap()" << std::endl;
	swap(charA, charB);
	std::cout << "(line:51) charA[" << charA << "]  charB[" << charB << "]" << std::endl;
	std::cout << "(line:52) max() -------> [" << max(charA, charB) << "]" << std::endl;
	std::cout << "(line:53) min() -------> [" << min(charA, charB) << "]\n" << std::endl;
	
	std::cout << "============= int =============" << std::endl;
	std::cout << "(line:56) intA[" << intA << "]  intB[" << intB << "]" << std::endl;
	std::cout << "(line:58) swap()" << std::endl;
	swap(intA, intB);
	std::cout << "(line:59) intA[" << intA << "]  intB[" << intB << "]" << std::endl;
	std::cout << "(line:60) max() -------> [" << max(intA, intB) << "]" << std::endl;
	std::cout << "(line:61) min() -------> [" << min(intA, intB) << "]\n" << std::endl;

	std::cout << "============ float ============" << std::endl;
	std::cout << "(line:64) floatA[" << floatA << "]  floatB[" << floatB << "]" << std::endl;
	std::cout << "(line:66) swap()" << std::endl;
	swap(floatA, floatB);
	std::cout << "(line:67) floatA[" << floatA << "]  floatB[" << floatB << "]" << std::endl;
	std::cout << "(line:68) max() -------> [" << max(floatA, floatB) << "]" << std::endl;
	std::cout << "(line:69) min() -------> [" << min(floatA, floatB) << "]\n" << std::endl;
	
	std::cout << "============ double ============" << std::endl;
	std::cout << "(line:72) doubleA[" << doubleA << "]  doubleB[" << doubleB << "]" << std::endl;
	std::cout << "(line:74) swap()" << std::endl;
	swap(doubleA, doubleB);
	std::cout << "(line:75) doubleA[" << doubleA << "]  doubleB[" << doubleB << "]" << std::endl;
	std::cout << "(line:76) max() -------> [" << max(doubleA, doubleB) << "]" << std::endl;
	std::cout << "(line:77) min() -------> [" << min(doubleA, doubleB) << "]\n" << std::endl;
	
	std::cout << "============ string ============" << std::endl;
	std::cout << "(line:80) stringAr[" << i << "][" << stringAr[i] << "]  stringAr[" << ii << "][" << stringAr[ii] << "]" << std::endl;
	std::cout << "(line:82) swap()" << std::endl;
	swap(stringAr[i], stringAr[ii]);
	std::cout << "(line:83) stringAr[" << i << "][" << stringAr[i] << "]  stringAr[" << ii << "][" << stringAr[ii] << "]" << std::endl;
	std::cout << "(line:84) max() -------> [" << ::max(stringAr[i], stringAr[ii]) << "]" << std::endl;
	std::cout << "(line:85) min() -------> [" << ::min(stringAr[i], stringAr[ii]) << "]\n" << std::endl;
	
	std::cout << "============ awesom ============" << std::endl;
	std::cout << "(line:88) awesomA[" << awesomA << "]  awesomB[" << awesomB << "]" << std::endl;
	std::cout << "(line:90) swap()" << std::endl;
	swap(awesomA, awesomB);
	std::cout << "(line:91) awesomA[" << awesomA << "]  awesomB[" << awesomB << "]" << std::endl;
	std::cout << "(line:92) max() -------> [" << max(awesomA, awesomB) << "]" << std::endl;
	std::cout << "(line:93) min() -------> [" << min(awesomA, awesomB) << "]\n" << std::endl;

	std::cout << "============ equleValue ============" << std::endl;
	intB = intA;
	std::cout << "(line:97) intA[" << intA << "]  intB[" << intB << "]" << std::endl;
	std::cout << "(line:98) intA[" << &intA << "]  intB[" << &intB << "]" << std::endl;
	std::cout << "(line:99) max() -------> [" << &max(intA, intB) << "]" << std::endl;
	std::cout << "(line:100) min() -------> [" << &min(intA, intB) << "]" << std::endl;
	return (0);
}