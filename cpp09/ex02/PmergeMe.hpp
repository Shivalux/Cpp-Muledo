/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:54:36 by sharnvon          #+#    #+#             */
/*   Updated: 2023/03/30 03:07:32 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <ctime>
# include <iomanip>
# include <exception>

# define ARGNUM 0
# define NUMCHR 1



class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(std::string numbers);
		PmergeMe(int argc, char **argv);
		PmergeMe(PmergeMe const &src);
		~PmergeMe(void);
		PmergeMe	&operator=(PmergeMe const &rhs);

		std::string	getNumbers(void);
		float		getTimeList(void);
		float		getTimeVector(void);
		void		printSortedVector(void);
		void		printSortedList(void);
		int			getSizeList(void);
		int			getSizeVector(void);

		class WrongArgument : public std::exception {
			virtual const char * what () const throw () {
				return ("PmergeMe: Error: wrong argument.\n(hint) $> ./PmergeMe [positive numbers]");
			}
		};
		class WrongCharacter : public std::exception {
			virtual const char * what () const throw () {
				return ("PmergerMe: Error: invalid character/s in arguments.");
			}
		};

	private:
		std::string			_numbers;
		float				_timeList;
		float				_timeVector;
		int					_sizeList;
		int					_sizeVector;
		std::list<int>		_sortedList;
		std::vector<int>	_sortedVector;
};

std::ostream	&operator<<(std::ostream &c, PmergeMe &rhs);

#endif