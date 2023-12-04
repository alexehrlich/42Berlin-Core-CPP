/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:33:17 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/01 12:59:29 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap default Construcotr called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name): _name(name)
{
	ClapTrap::_name = name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap name Construcotr called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& dt): _name(dt._name)
{
	ClapTrap::_name = dt._name + "_clap_name";
	_hitPoints = dt._hitPoints;
	_energyPoints = dt._energyPoints;
	_attackDamage = dt._attackDamage;
	std::cout << "DiamondTrap copy Construcotr called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& dt)
{
	if (this != &dt)
	{
		_name = dt._name;
		ClapTrap::_name = dt._name + "_clap_name";
		_hitPoints = dt._hitPoints;
		_energyPoints = dt._energyPoints;
		_attackDamage = dt._attackDamage;
	}
	std::cout << "DiamondTrap copy assignment Construcotr called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destrucotr called" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "DiamondTrap name: " << DiamondTrap::_name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}
