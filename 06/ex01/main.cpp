/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:47:24 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/15 09:42:29 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int main(void)
{
	Data*	d = new Data();

	std::cout << d->getX() << std::endl;
	std::cout << d->getY() << std::endl;
	std::cout << d->getXPtr() << std::endl;
	std::cout << d << std::endl << std::endl;

	d = Serialize::deserialize(Serialize::serialize(d));

	std::cout << d->getX() << std::endl;
	std::cout << d->getY() << std::endl;
	std::cout << d->getXPtr() << std::endl;
	std::cout << d << std::endl << std::endl;
	
	delete d;
	return (0);
}