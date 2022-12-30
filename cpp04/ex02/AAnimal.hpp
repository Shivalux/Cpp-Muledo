/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:46:19 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/20 15:21:15 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
	public:
		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(AAnimal &src);
		virtual ~AAnimal(void);
		AAnimal				&operator=(AAnimal &rhs);
		virtual void		makeSound(void) const = 0;
		std::string const	getType(void) const;
		void				setIdea(std::string idea, int index);

	protected:
		std::string	_type;
};

std::ostream &operator<<(std::ostream &out, AAnimal &rhs);

#endif