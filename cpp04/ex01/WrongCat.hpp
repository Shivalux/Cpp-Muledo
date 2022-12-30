/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:11:14 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/17 22:01:29 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGWrongCAT_HPP
# define WRONGWrongCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(WrongCat &src);
		~WrongCat(void);
		WrongCat	&operator=(WrongCat &rhs);
		void		makeSound(void) const;
};

std::ostream	&operator<<(std::ostream &out, WrongCat &rhs);

#endif