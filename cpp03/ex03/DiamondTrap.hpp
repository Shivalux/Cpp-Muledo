/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:43:50 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/17 16:04:53 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap &src);
		~DiamondTrap(void);
		DiamondTrap	&operator=(DiamondTrap &rhs);
		using 		ScavTrap::attack;
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		whoAmI(void);
		std::string	getName(void);
		
	private:
		std::string	_name;
};


std::ostream	&operator<<(std::ostream &out, DiamondTrap &rhs);

#endif