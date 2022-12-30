/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:28:18 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/22 23:51:24 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat &src);
		~Bureaucrat(void);
		Bureaucrat	&operator=(Bureaucrat &rhs);
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		gradeIncreament(void);
		void		gradeIncreament(int grade);
		void		gradeDecreament(void);
		void		gradeDecreament(int grade);
		class GradeTooHightException : public std::exception
		{
			public:
				virtual const char * what() const throw () {
					return (" >>ERROR: the bureaucrat's grade is too hight....");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw () {
					return (" >>ERROR: the bureaucrat's grade is too low....");
				}
		};

	private:
		std::string	_name;
		int			_grade;
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat &rhs);

#endif
