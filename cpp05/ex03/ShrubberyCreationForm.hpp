/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:47:21 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/24 11:54:40 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string taget);
		ShrubberyCreationForm(ShrubberyCreationForm &src);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm &rhs);
		void	beSigned(Bureaucrat &bureaucrat);
		void	execute(Bureaucrat const &bureaucrat) const;
	
	private:
		std::string	_taget;
};

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm &rhs);

#endif