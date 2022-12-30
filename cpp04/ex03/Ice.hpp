/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:09:51 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/19 19:28:57 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		// Ice(Ice &src);
		virtual ~Ice(void);
		// Ice	&operator=(Ice &rhs);
		// Ice	use(void);
		Ice		*clone(void) const;
		virtual void	use(ICharacter &taget);
};

std::ostream	&operator<<(std::ostream &out, Ice &rhs);

#endif