/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:04:19 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/31 20:59:48 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

// class AForm;

class Intern
{
	public:
		Intern(void);
		Intern(Intern &src);
		~Intern(void);
		Intern	&operator=(Intern &rhs);
		AForm	*makeForm(std::string formName, std::string taget);
		AForm	**getFormAddress(void);
		int		getCount(void) const;

	private:
		AForm		*_formAddress[1000];
		static int	_count;
};

std::ostream	&operator<<(std::ostream &out, Intern &rhs);

#endif