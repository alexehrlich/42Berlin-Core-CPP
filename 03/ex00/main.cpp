/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:54:10 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/29 10:45:03 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap cp1("cp1");
	ClapTrap cp2("cp2");
	ClapTrap cp3(cp2);
	ClapTrap cp4;

	std::cout << "cp4's name: " << cp4.getName() << std::endl;
	std::cout << "cp3's name: " << cp3.getName() << std::endl; 
	cp4 = cp3;
	
	cp1.attack("cp2");
	cp2.takeDamage(4);
	cp2.attack("cp1");
	cp1.takeDamage(1);
	cp2.beRepaired(1);
	std::cout << std::endl;
	
	std::cout << "cp2's hitpoints: " << cp2.getHitPoints() << std::endl;
	std::cout << "cp1's hitpoints: " << cp1.getHitPoints() << std::endl;
	std::cout << "cp3's hitpoints: " << cp3.getHitPoints() << std::endl;
	std::cout << "cp4's hitpoints: " << cp4.getHitPoints() << std::endl;
	std::cout << std::endl;
	return (0);
}