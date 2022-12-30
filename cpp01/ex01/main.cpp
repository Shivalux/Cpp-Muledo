/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:57:49 by sharnvon          #+#    #+#             */
/*   Updated: 2022/10/31 19:53:33 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int main(void)
{
	Zombie	*zombies;
	int		amount = 5;

	zombies = zombieHorde(amount, "FOO");
	if (zombies == NULL)
		return (EXIT_FAILURE);
	for (int i = 0; i < amount; i++)
	{
		zombies[i].announce();
	}
	delete [] zombies;
	std::cout << "end of main" << std::endl;
	return (EXIT_SUCCESS);
}