/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:53:53 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/19 20:51:31 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	public:
		Character(void);
		Character(std::string name);
		Character(Character &src);
		~Character(void);
		Character	&operator=(Character &rhs);
		std::string const	&getName(void) const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &taget);
		AMateria			**getSlot(void);
	
	private:
		std::string	_name;
		AMateria	*_slot[4];
};

std::ostream	&operator<<(std::ostream &out, Character &rhs);

#endif