/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 08:19:50 by aehrlich          #+#    #+#             */
/*   Updated: 2023/08/01 07:26:34 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{

public:
	Contact(std::string fN, std::string lN, std::string nN, std::string pN, std::string dS);
	Contact();
	~Contact();

std::string	getFirstName()const;
void		setFirstName(std::string firstName);

std::string	getLastName()const;
void		setLastName(std::string lastName);

std::string	getNickName()const;
void		setNickName(std::string nickName);

std::string	getPhoneNumber()const;
void		setPhoneNumber(std::string phoneNumber);

std::string	getDarkestSecret()const;
void	setDarkestSecret(std::string secret);


private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
};

#endif
