/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:50:03 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/09 18:56:20 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string.h>

int main(int argc, char **argv)
{
	std::ifstream	database;
	std::ifstream	input;
	BitcoinExchange	be;
	
	if (argc == 1)
	{
		std::cout << "Error: Could not open file." << std::endl;
		return (0);
	}
	else if (argc != 2)
	{
		std::cout << "Error: Too many arguments. Usage: ./btc <input.txt>" << std::endl;
		return (0);
	}
	try
	{
		be.readDB("data.csv");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (0);
	}
	input.open(argv[1]);
	if (!input.is_open())
	{
		std::cout << "Error: Could not open file." << std::endl;
		return (0);
	}
	be.calculate(input);
	input.close();
	return (0);
}
