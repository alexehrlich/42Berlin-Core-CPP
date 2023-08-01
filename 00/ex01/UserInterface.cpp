/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterface.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:37:19 by aehrlich          #+#    #+#             */
/*   Updated: 2023/08/01 16:03:54 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserInterface.hpp"

UserInterface::UserInterface()
{
}

UserInterface::~UserInterface()
{
}

void	UserInterface::introduction()
{
	std::cout << "Welcome to you personal phonebook. There are the following options:" << std::endl<<std::endl;
	std::cout << "- ADD\t\tsave new contact." << std::endl;
	std::cout << "- SEARCH\tdisplay a specific contact." << std::endl;
	std::cout << "- EXIT\t\tclose the phonebook." << std::endl<< std::endl;
	std::cout << "Choose between ADD, SEARCH and EXIT." << std::endl;
}

Contact	UserInterface::addRoutine()
{
	Contact c;
	
	c.setFirstName(_readField("Enter first name"));
	c.setLastName(_readField("Enter last name"));
	c.setPhoneNumber(_readField("Enter phone number"));
	c.setNickName(_readField("Enter nickname"));
	c.setDarkestSecret(_readField("Enter darkest secret"));
	std::cout << "Contact was created successfully" << std::endl << std::endl;
	return (c);
}

void	UserInterface::searchRoutine(PhoneBook book)
{
	std::string	indexString;
	Contact		*c;
	int			index;

	index = -1;
	if (book.isEmpty())
	{
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}
	_showAllEntries(book);
	while (index < 0 || index > 7)
	{
		std::cout << "Enter index for more information." << std::endl;
		std::getline(std::cin, indexString);
		index = std::atoi(indexString.c_str());
		if (index < 0 || index > 7)
			std::cout << "No valid index. Must be between 0 and 7 - both inclusive." << std::endl;
	}
	c = book.getContactAtIndex(index);
	if (!c)
	{
		std::cout << "No entry at index: " << index << std::endl;
		return ;
	}
	std::cout << "\nENTRY @ INDEX: " << index << std::endl;
	_showSingleEntry(*c);
}

std::string	UserInterface::_readField(std::string prompt)
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

int	UserInterface::_readIndex()
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

std::string	UserInterface::_getTruncatedString(std::string s)
{
	if (s.length() <= 10)
		return (s);
	return (s.substr(0, 9) + ".");
}

void	UserInterface::_showSingleEntry(Contact c)
{
	std::cout << "First Name\t:" << c.getFirstName() << std::endl;
	std::cout << "Last Name\t:" << c.getLastName() << std::endl;
	std::cout << "Nickname\t:" << c.getNickName() << std::endl;
	std::cout << "Phone number\t:" << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret\t:" << c.getDarkestSecret() << std::endl;
}

void	UserInterface::_showAllEntries(PhoneBook book)
{
	Contact	*c;
	int		idx;

	idx = 0;
	c = book.getContactAtIndex(idx);
	while (c)
	{
		std::cout << std::setw(10) << idx << "|";
		std::cout << std::setw(10) << _getTruncatedString(c->getFirstName()) << "|";
		std::cout << std::setw(10) << _getTruncatedString(c->getLastName()) << "|";
		std::cout << std::setw(10) << _getTruncatedString(c->getNickName()) << std::endl;
		c = book.getContactAtIndex(++idx);
	}
}
