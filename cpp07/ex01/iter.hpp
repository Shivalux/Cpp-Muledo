/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 06:21:22 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/28 07:01:13 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template < typename T >
void	iter(T *array, int size, void (*function)(const T&))
{
	for (int i = 0; i < size; i++)
		function(array[i]);
}

#endif