/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:54:10 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/29 12:36:05 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap ct("Clappie");
	ScavTrap st1("Scavie");
	ScavTrap st2("Scavo");

	ct.attack("Scavie");
	st1.takeDamage(ct.getAttackDamage());
	st1.attack("Clappie");
	ct.takeDamage(st1.getAttackDamage());
	st2.attack("Scavie");
	st1.takeDamage(st2.getAttackDamage());
	ct.beRepaired(3);
	st1.beRepaired(3);

	std::cout << ct.getName() <<" Hitpoints: " << ct.getHitPoints() << std::endl;
	std::cout << ct.getName() <<" Energy: " << ct.getEnergyPoints() << std::endl;
	std::cout << st1.getName() <<" Hitpoints: " << st1.getHitPoints() << std::endl;
	std::cout << st1.getName() <<" Energy: " << st1.getEnergyPoints() << std::endl;
	std::cout << st2.getName() <<" Hitpoints: " << st2.getHitPoints() << std::endl;
	std::cout << st2.getName() <<" Energy: " << st2.getEnergyPoints() << std::endl;
	return (0);
}