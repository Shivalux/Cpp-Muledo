/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:41:22 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/17 15:11:59 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap (FragTrap &src);
		~FragTrap(void);
		FragTrap	&operator=(FragTrap &rhs);
		void		attack(const std::string &taget);
		void		highFiveGuy(void);
};

std::ostream	&operator<<(std::ostream &out, FragTrap &rhs);

#endif