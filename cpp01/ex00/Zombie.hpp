/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:38:48 by sharnvon          #+#    #+#             */
/*   Updated: 2022/11/01 00:07:35 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include "iostream"

class Zombie{
	public:
		Zombie(std::string name);
		~Zombie(void);
		std::string	getName(void);
		void		announce(void);
	private:
		std::string	_name;
};

#endif