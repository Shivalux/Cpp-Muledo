/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:02:27 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/12 22:00:35 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const &src);
		~Fixed(void);
		Fixed	&operator=(Fixed const &rhs);
		bool	operator>(Fixed const &rhs);									//* add
		bool	operator>=(Fixed const &rhs);									//* add
		bool	operator<(Fixed const &rhs);									//* add
		bool 	operator<=(Fixed const &rhs);									//* add
		bool	operator==(Fixed const &rhs);									//* add
		bool	operator!=(Fixed const &rhs);									//* add
		Fixed	operator+(Fixed const &rhs);									//* add
		Fixed	operator-(Fixed const &rhs);									//* add
		Fixed	operator*(Fixed const &rhs);									//* add
		Fixed	operator/(Fixed const &rhs);									//* add
		Fixed	operator++(void);												//* add
		Fixed	operator++(int);												//* add
		Fixed	operator--(void);												//* add
		Fixed	operator--(int);												//* add
		static Fixed	&min(Fixed &fixedNum1, Fixed &fixedNum2);				//* add
		static Fixed	&min(Fixed const &fixedNum1, Fixed const &fixedNum2);	//* add
		static Fixed	&max(Fixed &fixedNum1, Fixed &fixedNum2);				//* add
		static Fixed	&max(Fixed const &fixedNum1, Fixed const &fixedNum2);	//* add
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_value;
		static const int	_fractionalBit;
};

std::ostream	&operator<<(std::ostream &c, Fixed const &rhs);

#endif