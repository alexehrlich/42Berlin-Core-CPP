/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:20:20 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/09 18:41:59 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& rhs);
		BitcoinExchange&	operator=(const BitcoinExchange& rhs);

		void	readDB(std::string filename);
		void	calculate(std::ifstream& input);

	private:
		std::map<std::string, double>	_database;
		bool							_validDate(const std::string& date);
		double							_getExchangeRate(const std::string& date);

	class DBReadException: public std::exception
	{
		virtual const char*	what() const throw()
		{
			return "Could not open Database.";
		}
	};
};

#endif