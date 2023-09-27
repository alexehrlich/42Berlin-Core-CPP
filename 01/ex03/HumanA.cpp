/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:11:15 by aehrlich          #+#    #+#             */
/*   Updated: 2023/09/26 09:06:36 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA(){}

void	HumanA::setWeapon(Weapon w)
{
	_weapon = w;
}

void	HumanA::attack()const
{
	std::cout << _name + " attacks with their " + _weapon.getType() << std::endl;
}
