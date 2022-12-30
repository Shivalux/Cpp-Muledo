/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:25:52 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/30 11:10:00 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <iostream>
# include <cstdlib>
# include <list>

class Span
{
	public:
		Span(void);
		Span(unsigned int n);
		Span(Span const &src);
		~Span(void);
		Span			&operator=(Span const &rhs);
		void			addNumber(int number);
		int				shortestSpan(void);
		int				longestSpan(void);
		void			addNumberRange(std::list<int> &listNumbers);
		void			addNumberRange(std::list<int>::iterator begin, std::list<int>::iterator end);
		std::list<int>	&getListNumber(void);
		unsigned int	getN(void) const;
		class shortestSpanError : public std::exception {
			virtual const char *what() const throw() {
				return ("shortestSpan) ERROR: Have not enough numbers stored for calculations...");
			}
		};
		class longestSpanError : public std::exception {
			virtual const char *what() const throw() {
				return ("longesttSpan) ERROR: Have not enough numbers stored for calculations...");
			}
		};
		class addNumberError : public std::exception {
			virtual const char *what() const throw () {
				return ("(addNumber) ERROR: Have not enough space available....");
			}
		};

	private:
		unsigned int	_n;
		std::list<int>	_listNumber;
};

std::ostream	&operator<<(std::ostream &out, Span &rhs);

#endif