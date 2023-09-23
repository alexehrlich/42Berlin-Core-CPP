/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 08:21:22 by aehrlich          #+#    #+#             */
/*   Updated: 2023/09/23 07:35:45 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string fN, std::string lN, std::string nN, std::string pN, std::string dS) :
	_firstName(fN), _lastName(lN), _nickName(nN),
	_phoneNumber(pN), _darkestSecret(dS)
{
}

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string	Contact::getFirstName()const
{
	return this->_firstName;
}

void	Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
}

std::string	Contact::getLastName()const
{
	return this->_lastName;
}

void	Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

std::string	Contact::getNickName()const
{
	return this->_nickName;
}

void	Contact::setNickName(std::string nickName)
{
	this->_nickName = nickName;
}

std::string	Contact::getPhoneNumber()const
{
	return this->_phoneNumber;
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

std::string	Contact::getDarkestSecret()const
{
	return this->_darkestSecret;
}

void	Contact::setDarkestSecret(std::string secret)
{
	this->_darkestSecret = secret;
}
