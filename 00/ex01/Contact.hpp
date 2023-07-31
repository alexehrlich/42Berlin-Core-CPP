/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 08:19:50 by aehrlich          #+#    #+#             */
/*   Updated: 2023/07/31 13:51:27 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{

public:
	Contact(std::string fN, std::string lN, std::string nN, int pN, std::string dS);
	Contact();
	~Contact();

std::string	getFirstName()const;
void		setFirstName(std::string firstName);

std::string	getLastName()const;
void		setLastName(std::string lastName);

std::string	getNickName()const;
void		setNickName(std::string nickName);

int			getPhoneNumber()const;
void		setPhoneNumber(int phoneNumber);

std::string	getDarkestSecret()const;
void	setDarkestSecret(std::string secret);


private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	int			_phoneNumber;
	std::string	_darkestSecret;
};

#endif
