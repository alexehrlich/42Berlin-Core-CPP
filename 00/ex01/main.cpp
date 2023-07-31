/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:02:02 by aehrlich          #+#    #+#             */
/*   Updated: 2023/07/31 10:50:01 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	pb;

	std::cout << "Welcome to you personal phonebook. Choose one one of the following options:" << std::endl<<std::endl;
	std::cout << "ADD\t\tsave new contact." << std::endl;
	std::cout << "SEARCH\t\tdisplay a specific contact." << std::endl;
	std::cout << "EXIT\t\tclose the phonebook." << std::endl;
	std::cout << "Choose one of the options:" << std::endl;
	return (EXIT_SUCCESS);
}
