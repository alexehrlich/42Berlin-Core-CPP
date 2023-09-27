/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:11:15 by aehrlich          #+#    #+#             */
/*   Updated: 2023/09/26 09:23:23 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_weapon = NULL;
	_name = name;
}

HumanB::~HumanB(){}

void	HumanB::setWeapon(Weapon& w)
{
	_weapon = &w;
}

void	HumanB::attack()const
{
	if (!_weapon)
	{
		std::cout <<_name + " has no weapon" << std::endl;
		return ;
	}
	std::cout << _name + " attacks with their " + _weapon->getType() << std::endl;
}
