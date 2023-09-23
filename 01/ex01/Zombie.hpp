/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 07:25:32 by aehrlich          #+#    #+#             */
/*   Updated: 2023/09/23 08:47:38 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie
{
	public:
		Zombie();
		~Zombie();
		
		void			announce(void)const;
		static Zombie*	zombieHorde(int N, std::string name);
		void			setName(std::string name);

	private:
		std::string	_name;
};
#endif
