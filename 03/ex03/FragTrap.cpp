/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:43:55 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/29 12:44:55 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default Construcotr called" << std::endl;
}

FragTrap::FragTrap(const std::string& name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap: " << _name << " called name constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& ft)
{
	this->_name = ft.getName();
	this->_energyPoints = ft._energyPoints;
	this->_hitPoints = ft.getHitPoints();
	this->_attackDamage = ft.getAttackDamage();
	std::cout << "FragTrap: " << _name << " called copy constructor" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& ft)
{
	this->_name = ft.getName();
	this->_energyPoints = ft._energyPoints;
	this->_hitPoints = ft.getHitPoints();
	this->_attackDamage = ft.getAttackDamage();
	std::cout << "FragTrap: " << _name << " called copy assignment constructor" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: " << _name << " destroyed" << std::endl;
}

void	FragTrap::attack(const std::string& target)
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
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" <<std::endl;
}

void	FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap " << _name << " needs a HighFive!" << std::endl;
}
