/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:25:11 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/29 18:12:22 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>

template< class T >
int easyfind(T &container, int find)
{
	if (std::find(container.begin(), container.end(), find) == container.end())
		throw (std::string("NOT FOUND....."));
	return (*(std::find(container.begin(), container.end(), find)));
}

#endif