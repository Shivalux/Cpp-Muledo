/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:57:49 by sharnvon          #+#    #+#             */
/*   Updated: 2022/10/31 19:03:02 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int main(void)
{
	Zombie	*zombie;

	randomChump("Foo");
	zombie = newZombie("Faa");
	zombie->announce();
	delete(zombie);
	return (EXIT_SUCCESS);
}