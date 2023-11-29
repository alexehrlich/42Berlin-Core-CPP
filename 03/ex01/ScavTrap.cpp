/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:43:55 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/29 12:32:16 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default Construcotr called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap: " << _name << " called name constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ct)
{
	this->_name = ct.getName();
	this->_energyPoints = ct._energyPoints;
	this->_hitPoints = ct.getHitPoints();
	this->_attackDamage = ct.getAttackDamage();
	std::cout << "ScavTrap: " << _name << " called copy constructor" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& ct)
{
	this->_name = ct.getName();
	this->_energyPoints = ct._energyPoints;
	this->_hitPoints = ct.getHitPoints();
	this->_attackDamage = ct.getAttackDamage();
	std::cout << "ScavTrap: " << _name << " called copy assignment constructor" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: " << _name << " destroyed" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "Attack faild: no energy points" << std::endl;
		return ;
	}
	if (this->_hitPoints == 0)
	{
		std::cout << "Attack faild: no hit points" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" <<std::endl;
}

void	ScavTrap::guardGate(void) const
{
	std::cout << "ScavTrap " << _name << " is now a gate keeper." << std::endl;
}
