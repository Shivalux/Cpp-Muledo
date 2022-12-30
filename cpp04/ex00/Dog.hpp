/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:25:32 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/18 17:50:27 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(Dog &src);
		virtual ~Dog(void);
		Dog				&operator=(Dog &rhs);
		virtual void	makeSound(void) const;
};

std::ostream	&operator<<(std::ostream &out, Dog &rhs);

#endif