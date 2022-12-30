/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:02:38 by sharnvon          #+#    #+#             */
/*   Updated: 2022/10/29 17:28:13 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	this->firstName = "-";
	this->lastName = "-";
	this->nickName = "-";
	this->phoneNumber = "-";
	this->darkestSecret = "-";
}

Contact::Contact(std::string first, std::string last, std::string nick, std::string number, std::string secret)
	: firstName(first), lastName(last), nickName(nick), phoneNumber(number), darkestSecret(secret) {};

/* get value of contact by using define keyword*/
/*FIRST, LAST, NICK, PHONE, SECRET*/
std::string	Contact::cGet(int get)
{
	if (get == FIRST)
		return (this->firstName);
	else if (get == LAST)
		return (this->lastName);
	else if (get == NICK)
		return (this->nickName);
	else if (get == PHONE)
		return (this->phoneNumber);
	else if (get == SECRET)
		return (this->darkestSecret);
	std::cout << "wrong information require :(" << std::endl;
	return ("");
}

/*add value of contact by using define keyword*/
/*FIRST, LAST, NICK, PHONE, SECRET*/
void	Contact::cAdd(std::string add, int mode)
{
	if (mode == FIRST)
		firstName = add;
	else if (mode == LAST)
		lastName = add;
	else if (mode == NICK)
		nickName = add;
	else if (mode == PHONE)
		phoneNumber = add;
	else if (mode == SECRET)
		darkestSecret = add;
	else
		std::cout << "wrong mode in add :(" << std::endl;
}

void	Contact::cPrint(void)
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "• first_name: " << this->firstName << std::endl;
	std::cout << "• last_name: " << this->lastName << std::endl;
	std::cout << "• nickname: " << this->nickName << std::endl;
	std::cout << "• phone_number: " << this->phoneNumber << std::endl;
	std::cout << "• darkest_secret: " << this->darkestSecret << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

Contact::~Contact(void)
{
}