/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:39:23 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/18 18:22:58 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
		Brain(void);
		Brain(Brain &src);
		~Brain(void);
		Brain 		&operator=(Brain &rhs);
		std::string	&getIdea(int index);
		
		
	private:
		std::string	_idea[100];
};

#endif