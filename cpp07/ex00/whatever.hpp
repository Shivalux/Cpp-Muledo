/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:49:50 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/29 14:07:54 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template < typename T >
T const	&min(T const &x, T const &y)
{
	return (x < y ? x : y);
}

template < typename T >
T const	&max(T const &x, T const &y)
{
	return (x > y ? x : y);
}

template < typename T >
void	swap(T &x, T &y)
{
	T	tmp;
	tmp = x;
	x = y;
	y = tmp;
}

#endif