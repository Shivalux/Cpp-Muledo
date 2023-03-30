/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 23:46:04 by sharnvon          #+#    #+#             */
/*   Updated: 2023/03/28 11:29:23 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <algorithm>
# include <fstream>
# include <exception>

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(std::string fileName);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange(void);
		BitcoinExchange					&operator=(BitcoinExchange &rhs);
		float							exchangeValue(std::string date, float value);
		std::string						getFileName(void);
		std::map<std::string, float>	getExchangeDataBase(void);
		bool							isData(void);

	private:
		std::string					_fileName;
		bool						_isData;
		std::map<std::string, float>	_exchangeDataBase;
};

std::ostream	&operator<<(std::ostream &c, BitcoinExchange &rhs);

#endif