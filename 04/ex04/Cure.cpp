/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:46:43 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/04 15:57:06 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::~Cure() {}

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
