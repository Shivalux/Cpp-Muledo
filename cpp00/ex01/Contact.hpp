/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:31:08 by sharnvon          #+#    #+#             */
/*   Updated: 2022/10/29 02:57:46 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>

# define FIRST	1
# define LAST	2
# define NICK	3
# define PHONE	4
# define SECRET	5

class	Contact{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;
	public:
		Contact(void);
		Contact(std::string first, std::string last, std::string nick, std::string number, std::string secret);
		std::string	cGet(int get);
		void		cAdd(std::string add, int mode);
		void		cPrint(void);
		~Contact(void);
};
#endif