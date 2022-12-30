/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:11:14 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/17 22:22:17 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(Cat &src);
		virtual 		~Cat(void);
		Cat				&operator=(Cat &rhs);
		virtual void	makeSound(void) const;
};

std::ostream	&operator<<(std::ostream &out, Cat &rhs);

#endif