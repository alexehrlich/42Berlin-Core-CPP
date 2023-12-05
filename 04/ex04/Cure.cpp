/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:46:43 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/05 10:25:12 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::~Cure() {}

Cure::Cure()
{
	_type = "cure";
	std::cout << "New Cure created" << std::endl;
}

AMateria*	Cure::clone() const
{
	Cure*	cure = new Cure();
	cure->_type = "cure";
	return (cure);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << " 's wounds *" << std::endl;
}
