/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:02:05 by sharnvon          #+#    #+#             */
/*   Updated: 2023/03/30 23:01:57 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <exception>
# include <cstring>
# include <deque>

class RPN
{
	public:
		RPN(void);
		RPN(int argc, char **argv);
		RPN(RPN const &src);
		~RPN(void);
		
		RPN			&operator=(RPN const &rhs);
		int			getResult(void);
		void		printIN(void);
		std::string	getRPN(void);

		class InvalidFomatArguments : public std::exception {
			virtual const char *what() const throw() {
				return ("NPR: Error: invalid fomate in argument.");
			}
		};

		class InvalidArguments : public std::exception {
			virtual const char *what() const throw() {
				return ("NPR: Error: wrong argument.\n"
					"(hint) $> ./NPR [an inverted Polish mathmatical expression with number range 0 - 9 and operator +, -, *, /]");
			}
		};

	private:
		int					_result;
		std::deque<char>	_IN;
		std::string			_RPN;
		
};

std::ostream	&operator<<(std::ostream &c, RPN &rhs);

#endif