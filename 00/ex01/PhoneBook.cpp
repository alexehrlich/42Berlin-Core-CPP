/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 08:18:18 by aehrlich          #+#    #+#             */
/*   Updated: 2023/07/31 18:01:00 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
	this->_addIndex = 0;
}

PhoneBook::~PhoneBook()
{	
}

void	PhoneBook::addContact(Contact c)
{
	this->_contatcs[this->_addIndex % 8] = c;
	_addIndex++;
}

void	PhoneBook::searchContact(int index)
{
	if (index > 7 || index < 0)
		std::cout << "Invalid index. Must be between 0 and 7." << std::endl;
	else if (index >= _addIndex)
		std::cout << "No user at index" << index << std::endl;
	else
		std::cout << _contatcs[index].getFirstName() << std::endl;
}