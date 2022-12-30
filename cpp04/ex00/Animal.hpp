/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:46:19 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/17 22:21:49 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(Animal &src);
		virtual ~Animal(void);
		Animal				&operator=(Animal &rhs);
		virtual void		makeSound(void) const;
		std::string const	getType(void) const;

	protected:
		std::string	_type;
};

std::ostream &operator<<(std::ostream &out, Animal &rhs);

#endif