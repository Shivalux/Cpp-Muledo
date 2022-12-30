/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:31:29 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/30 23:27:26 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <ostream>
# include "Bureaucrat.hpp"
# include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExec;

	public:
		AForm(void);
		AForm(std::string name, int gradeSign, int gradeExec);
		AForm(AForm &src);
		virtual ~AForm(void);
		AForm			&operator=(AForm const &src);
		virtual void	beSigned(Bureaucrat &bureaucrat) = 0;
		virtual void	execute(Bureaucrat const &bureaucrat) const = 0;
		std::string		getName(void) const;
		bool			getSigned(void) const;
		int				getGradeSign(void) const;
		int				getGradeExec(void) const;
		void			setSigned(bool sign);
		class GradeisOutOFRange : public std::exception {
			public:
				virtual	const char * what() const throw () {
					
					return (" >>ERROR: Requirement is out of range, (hint) range must between 1 to 150.");
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char * what () const throw () {
					return ("the requirment of the form is highter.....");
				}
		};
		class FormNotSigned : public std::exception {
			public:
				virtual const char * what () const throw () {
					return ("the form hadn't been sign for executtion.....");
				}
		};
};

std::ostream	&operator<<(std::ostream &out, AForm &rhs);

#endif