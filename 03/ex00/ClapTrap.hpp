/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:49:17 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/29 10:31:33 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& ct);
		~ClapTrap();
		ClapTrap&	operator=(const ClapTrap& c);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string		getName() const;
		unsigned int	getHitPoints() const;
		int				getEnergypoints() const;
		int				getAttackDamage() const;

	private:
		std::string		_name;
		unsigned int	_hitPoints;
		int				_energyPoints;
		int				_attackDamage;
};

#endif