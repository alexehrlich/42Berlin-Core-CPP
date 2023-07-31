/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 08:19:50 by aehrlich          #+#    #+#             */
/*   Updated: 2023/07/31 09:51:14 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{

public:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	int			phoneNumber;
	std::string	darkestSecret;

	Contact(std::string fN, std::string lN, std::string nN, int pN, std::string dS);
	Contact();
	~Contact();
};

#endif
