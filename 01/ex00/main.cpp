/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 08:11:07 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/22 12:38:41 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie1 = Zombie::newZombie("HEAPIE");

	zombie1->announce();
	Zombie::randomChump("STACKIE");
	delete zombie1;
	
	return (0);
}
