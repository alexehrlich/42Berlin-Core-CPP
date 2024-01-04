/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:50:03 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/04 14:55:09 by aehrlich         ###   ########.fr       */
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
		std::cout << "Error: Could not open file." << std::endl;
	else if (argc != 2)
		std::cout << "Error: Too many arguments. Usage: ./btc <input.txt>" << std::endl;
	input.open(argv[1]);
	if (input.fail())
	{
		std::cout << "Error: Could not open file." << std::endl;
		return (0);
	}
	be.calculate(input);
	return 0;
}
