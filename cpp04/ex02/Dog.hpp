/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:25:32 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/20 15:10:05 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog : public AAnimal
{
	public:
		Dog(void);
		Dog(Dog &src);
		virtual	~Dog(void);
		Dog				&operator=(Dog &rhs);
		virtual void	makeSound(void) const;
		Brain			*getBrain(void);

	private:
		Brain	*_brain;
};

std::ostream	&operator<<(std::ostream &out, Dog &rhs);

#endif