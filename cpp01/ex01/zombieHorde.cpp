/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:07:38 by sharnvon          #+#    #+#             */
/*   Updated: 2022/10/31 19:53:19 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static std::string	itoString(int number);

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombies;
	int		count;

	count = 0;
	if (N <= 0)
		return (NULL);
	zombies = new Zombie[N];
	while (count < N)
	{
		zombies[count].setName(name + '[' + itoString(count + 1) + ']');
		count++;
	}
	return(zombies);
}

static std::string	itoString(int number)
{
	std::string	tmp;
	std::string result;
	char		num;

	while (number > 0)
	{
		num = ('0' +(number % 10));
		tmp += num;
		number /= 10;
	}
	for (int i = 0, j = tmp.length() - 1; j >= 0; i++, j--)
		result += tmp[j];
	return (result);
}