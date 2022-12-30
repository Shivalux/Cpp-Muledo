/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:48:28 by sharnvon          #+#    #+#             */
/*   Updated: 2022/10/29 17:27:15 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class Contact;

class	PhoneBook{
	public:
		Contact	contact[8];
		void	phoneBookTable(void);
		void	phoneBookContact(int index);
		~PhoneBook(void);
};

#endif