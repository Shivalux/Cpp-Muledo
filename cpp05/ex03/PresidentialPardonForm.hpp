/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:58:39 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/24 11:55:11 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string taget);
		PresidentialPardonForm(PresidentialPardonForm &src);
		~PresidentialPardonForm(void);
		PresidentialPardonForm	&operator=(PresidentialPardonForm &rhs);
		void	beSigned(Bureaucrat &bureaucrat);
		void	execute(Bureaucrat const &bureaucrat) const;

	private:
		std::string	_taget;
};

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm &rhs);

#endif