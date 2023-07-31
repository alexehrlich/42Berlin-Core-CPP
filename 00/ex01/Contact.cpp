/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 08:21:22 by aehrlich          #+#    #+#             */
/*   Updated: 2023/07/31 09:56:52 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string fN, std::string lN, std::string nN, int pN, std::string dS) :
	firstName(fN), lastName(lN), nickName(nN),
	phoneNumber(pN), darkestSecret(dS)
{
}

Contact::Contact()
{
}

Contact::~Contact()
{
}
