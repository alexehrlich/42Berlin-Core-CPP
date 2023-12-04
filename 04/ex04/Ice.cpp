/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:24:35 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/04 16:25:14 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::~Ice() {}

AMateria*	Ice::clone() const
{
	Ice*	cure = new Ice();
	cure->_type = "cure";
	return (cure);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice ball at " << target.getName()<< std::endl;
}
