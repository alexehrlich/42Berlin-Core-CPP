/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:54:55 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/29 10:31:36 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap: Called default constructor" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap: Called name constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ct): _name(ct._name), _hitPoints(ct._hitPoints), _energyPoints(ct._energyPoints), _attackDamage(ct._attackDamage)
{
	std::cout << "ClapTrap: Called copy constructor" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: Called destructor" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& c)
{
	if (this != &c)
	{
		this->_name = c._name;
		this->_hitPoints = c._hitPoints;
		this->_energyPoints = c._energyPoints;
		this->_attackDamage = c._attackDamage;
		std::cout << "Called copy assignment constructor" << std::endl;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
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
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" <<std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= _hitPoints)
	{
		_hitPoints = 0;
		std::cout << _name << " has not hitpoints" << std::endl;
		return ;
	}
	std::cout << _name << " takes " << amount << " points of damage." << std::endl;
	_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "Repair faild: no energy points" << std::endl;
		return ;
	}
	std::cout << _name << " takes " << amount << " points of repair." << std::endl;
	_hitPoints += amount;
	_energyPoints--;
}

std::string		ClapTrap::getName() const
{
	return (_name);
}

unsigned int	ClapTrap::getHitPoints() const
{
	return (_hitPoints);
}
int				ClapTrap::getEnergypoints() const
{
	return (_energyPoints);
}

int				ClapTrap::getAttackDamage() const
{
	return (_attackDamage);
}
