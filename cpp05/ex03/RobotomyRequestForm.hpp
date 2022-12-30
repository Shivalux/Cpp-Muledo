/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 08:14:44 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/24 11:54:56 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <unistd.h>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string taget);
		RobotomyRequestForm(RobotomyRequestForm &src);
		~RobotomyRequestForm(void);
		RobotomyRequestForm	&operator=(RobotomyRequestForm &rhs);
		void	beSigned(Bureaucrat &bureaucrat);
		void	execute(Bureaucrat const &bureaucrat) const;

	private:
		std::string	_taget;

};

std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm &rhs);

#endif