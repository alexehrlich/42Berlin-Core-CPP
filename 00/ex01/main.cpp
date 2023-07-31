/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:02:02 by aehrlich          #+#    #+#             */
/*   Updated: 2023/07/31 17:36:53 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

std::string	readRoutine(std::string prompt)
{
	std::string	line;

	std::cout << prompt << ":" << std::endl;
	while (std::getline(std::cin, line) && line.empty())
	{
		std::cout << "ERROR: Field must not be empty." << std::endl;
		std::cout << prompt << ":" << std::endl;
	}
	return (line);
}

Contact	readContactInfo()
{
	Contact c;
	
	c.setFirstName(readRoutine("Enter first name"));
	c.setLastName(readRoutine("Enter last name"));
	c.setNickName(readRoutine("Enter phone number"));
	c.setNickName(readRoutine("Enter nickname"));
	c.setDarkestSecret(readRoutine("Enter darkest secret"));
	std::cout << "Contact was created successfully" << std::endl << std::endl;
	return (c);
}

int	readIndex()
{
	std::string	line;

	std::cout << "Enter index:" << std::endl;
	while (std::getline(std::cin, line) && line.empty())
	{
		std::cout << "ERROR: Field must not be empty." << std::endl;
		std::cout << "Enter index:" << std::endl;
	}
	return (std::atoi(line.c_str()));
}

int	main()
{
	PhoneBook	pb;
	Contact		tempContact;
	std::string	inputString;

	std::cout << "Welcome to you personal phonebook. There are the following options:" << std::endl<<std::endl;
	std::cout << "- ADD\t\tsave new contact." << std::endl;
	std::cout << "- SEARCH\tdisplay a specific contact." << std::endl;
	std::cout << "- EXIT\t\tclose the phonebook." << std::endl<< std::endl;
	std::cout << "Choose between ADD, SEARCH and EXIT." << std::endl;
	while (std::getline(std::cin, inputString) && inputString != "EXIT")
	{
		if (inputString == "ADD")
			pb.addContact(readContactInfo());
		else if (inputString == "SEARCH")
			pb.searchContact(readIndex());
		else
			std::cout << "ERROR:" <<"No valid option." << std::endl;
		std::cout << "Choose between ADD, SEARCH and EXIT." << std::endl;
	}
	return (EXIT_SUCCESS);
}
