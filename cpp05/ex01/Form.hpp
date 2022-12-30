/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:31:29 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/30 23:25:17 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <ostream>
# include "Bureaucrat.hpp"
# include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExec;

	public:
		Form(void);
		Form(std::string name, int gradeSign, int gradeExec);
		Form(Form &src);
		~Form(void);
		Form		&operator=(Form const &src);
		void		beSigned(Bureaucrat &bureaucrat);
		std::string	getName(void) const;
		bool		&getSigned(void);
		int			getGradeSign(void) const;
		int			getGradeExec(void) const;
		class GradeTooHightException : public std::exception {
			public:
				virtual const char * what() const throw () {
					return ("grade is too hight......");
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char * what () const throw () {
					return ("grade is too low.......");
				}
		};
};

std::ostream	&operator<<(std::ostream &out, Form &rhs);

#endif