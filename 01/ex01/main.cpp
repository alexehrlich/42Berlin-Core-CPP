/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 08:11:07 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/22 15:01:25 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombieHorde = Zombie::zombieHorde(3, "James");
	
	zombieHorde[1].setName("Alex");
	zombieHorde[2].setName("Sophie");
	delete [] zombieHorde;
	return (0);
}
