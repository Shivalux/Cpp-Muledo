/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:11:14 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/20 15:10:02 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>

class Cat : public AAnimal
{
	public:
		Cat(void);
		Cat(Cat &src);
		virtual	~Cat(void);
		Cat				&operator=(Cat &rhs);
		virtual void	makeSound(void) const;
		Brain			*getBrain(void);
	
	private:
		Brain	*_brain;
};

std::ostream	&operator<<(std::ostream &out, Cat &rhs);

#endif