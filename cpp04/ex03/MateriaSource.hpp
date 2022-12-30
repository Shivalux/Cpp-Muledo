/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:47:39 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/20 14:55:33 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource &src);
		virtual ~MateriaSource(void);
		MateriaSource	&operator=(MateriaSource &rhs);
		void			learnMateria(AMateria *m);
		AMateria		*createMateria(std::string const &type);
		AMateria		**getSlot(void);

	private:
		AMateria	*_slot[4];
};

std::ostream	&operator<<(std::ostream &out, MateriaSource &hrs);

#endif