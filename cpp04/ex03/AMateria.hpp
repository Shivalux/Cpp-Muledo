/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:40:56 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/19 21:37:15 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	private:
		AMateria(void);

	protected:
		std::string	_type;

	public:
		AMateria(std::string const &type);
		AMateria(AMateria &src);
		virtual ~AMateria(void);
		AMateria			&operator=(AMateria &rhs);
		std::string const	&getType(void) const;
		void				setType(std::string type);
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);
};

#endif