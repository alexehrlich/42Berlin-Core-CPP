/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 08:18:18 by aehrlich          #+#    #+#             */
/*   Updated: 2023/08/01 08:19:09 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
	_addIndex = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::addContact(Contact c)
{
	_contatcs[_addIndex % 8] = c;
	_addIndex++;
}

Contact*	PhoneBook::getContactAtIndex(int index)
{
	if (index > 7 || index < 0 || index >= _addIndex)
		return (NULL);
	return (_contatcs + index);
}

bool	PhoneBook::isEmpty()const
{
	return (_addIndex == 0);
}
