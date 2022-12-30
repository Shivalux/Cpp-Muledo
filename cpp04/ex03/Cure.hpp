/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:43:39 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/19 19:29:57 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		virtual ~Cure(void);
		Cure	*clone(void) const;
		void	use(ICharacter &taget);
};

std::ostream	&operator<<(std::ostream &out, Cure &rhs);

#endif