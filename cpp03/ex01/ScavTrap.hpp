/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:52:37 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/17 15:14:21 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap &src);
		~ScavTrap(void);
		ScavTrap	&operator=(ScavTrap &rhs);
		void		attack(const std::string &taget);
		void		guandGate(void);
};

std::ostream	&operator<<(std::ostream &out, ScavTrap &rhs);

#endif