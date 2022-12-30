/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:01:44 by sharnvon          #+#    #+#             */
/*   Updated: 2022/11/01 13:53:08 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {
	public:
		Weapon(void);
		Weapon(std::string set);
		~Weapon(void);
		std::string const	&getType(void) const;
		void				setType(std::string set);

	private:
		std::string	_type;
};

#endif