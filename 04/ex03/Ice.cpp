/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:24:35 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/05 10:24:18 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::~Ice() {}

Ice::Ice()
{
	_type = "ice";
	std::cout << "New Ice created" << std::endl;
}

AMateria*	Ice::clone() const
{
	Ice*	ice = new Ice();
	ice->_type = "ice";
	return (ice);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice ball at " << target.getName()<< std::endl;
}
