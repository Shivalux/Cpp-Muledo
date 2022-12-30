/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:46:19 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/17 22:21:38 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal &src);
		~WrongAnimal(void);
		WrongAnimal			&operator=(WrongAnimal &rhs);
		void				makeSound(void) const;
		std::string const	getType(void) const;

	protected:
		std::string	_type;
};

std::ostream &operator<<(std::ostream &out, WrongAnimal &rhs);

#endif