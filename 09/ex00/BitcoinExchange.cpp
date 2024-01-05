/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:30:32 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/05 09:14:08 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sstream>
#include <string>
#include <fstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	databaseInFile;
	std::string		line;
	std::string		date;
	std::string		exchangeRate;

	databaseInFile.open("data.csv");
	/*if (databaseInFile.fail())
		return ; */
	std::getline(databaseInFile, line); //skip first line
	while (std::getline(databaseInFile, line))
	{
		std::istringstream	iss(line);
		std::getline(iss, date, ',');
		std::getline(iss, exchangeRate, ',');
		_database[date] = std::strtod(exchangeRate.c_str(), NULL);
	}
	databaseInFile.close();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs)
{
	if (this != &rhs)
		this->_database = rhs._database;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this != &rhs)
		this->_database = rhs._database;
	return (*this);
}

void	BitcoinExchange::calculate(std::ifstream& input)
{
	std::string	line;
	std::getline(input, line);
	if (line != "date | value")
	{
		std::cout << "Error: Wrong file header." << std::endl;
		return ;
	}
	while (std::getline(input, line))
	{
		if (line.length() < 14)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, 10);
		std::string delim = line.substr(10, 3);
		std::string valString = line.substr(13);
		char*		endptr;
		double		value = std::strtod(valString.c_str(), &endptr);
		if (!_validDate(date) || delim != " | " || *endptr != '\0')
			std::cout << "Error: bad input => " << line << std::endl;
		else if (value < 0)
			std::cout << "Error: not a positive number" << std::endl;
		else if (value >  2147483647)
			std::cout << "Error: too large number" << std::endl;
		else
		{
			double	exchangeRate = _getExchangeRate(date);
			if (exchangeRate == -1)
			{
				std::cout << "Error: date too early => " << date << std::endl;
				continue;
			}
			std::cout << date << " => " << value << " = " << value * exchangeRate << std::endl;
		}
	}
}

bool	BitcoinExchange::_validDate(const std::string& date)
{
	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	std::istringstream	iss(date);
	int		year, month, day;
	char	dash1, dash2;
	iss >> year >> dash1 >> month >> dash2 >> day; //iss tries to exctract from the stream
	// Check the extraction was successful
	if (iss.fail() || !iss.eof())
		return (false);
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31 || dash1 != '-' || dash2 != '-')
		return (false);
	return (true);
}

int compareDates(const std::string& date1, const std::string& date2) {
	if (date1 > date2)
		return 1;
	return 2;
}

double	BitcoinExchange::_getExchangeRate(const std::string& date)
{
	std::map<std::string, double>::iterator it = _database.begin();
	for (; it != _database.end(); it++)
		if (it->first.compare(date) == 0) 
			return it->second;
	it = _database.lower_bound(date); //searches for the next greater key (date)
	if (it == _database.begin()) 
		return -1.0;
	it--; //we want the smaller one, so the one before the next greater one --> decrement
	return it->second;
}

