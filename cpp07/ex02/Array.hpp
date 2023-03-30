/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 07:48:25 by sharnvon          #+#    #+#             */
/*   Updated: 2023/03/28 10:16:21 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include<iostream>
template< typename T >
class Array
{
	public:
		Array<T>(void) : _size(0)
		{	
			std::cout << "Defualt constructor is called." << std::endl;
			_array = new T[0] ();
		}
		Array<T>(unsigned int n) : _size(n)
		{ 
			std::cout << "Constructor is called." << std::endl;
			_array = new T[n] ();
		}
		Array<T>(Array const &src)
		{
			std::cout << "Copy constructor is called." << std::endl;
			_array = new T[src._size];
			_size = src._size;
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = src._array[i];
		}
		~Array<T>(void)
		{
			std::cout << "Destructorr is called." << std::endl;
			try
			{
				delete [] _array;
			}
			catch(const std::exception &exception)
			{
				std::cerr << exception.what() << std::endl;
			}
			
		}
		Array<T>	&operator=(Array<T> const &rhs)
		{
			std::cout << "Copy assignment operator is called." << std::endl;
			(void)rhs;
			if( this != &rhs)
			{
				delete [] _array;
				_size = rhs._size;
				_array = new T[_size] ();
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = rhs._array[i];
			}
			return (*this);
		}
		T		&operator[](unsigned int i)
		{
			// std::cout << "Element accessed operator is called." << std::endl;
			if (i >= _size)
				throw (std::out_of_range("ERROR: the index is out of bounds...."));
			return (_array[i]);
		}
		unsigned int	size(void) const { return(_size); }

	private:
		unsigned int	_size;
		T				*_array;
};

template< typename T>
std::ostream	&operator<<(std::ostream &out, Array<T> &rhs)
{
	for (unsigned int i = 0; i < rhs.size(); i++)
		std::cout << "[" << rhs[i] << "]";
	return (out);
}

#endif