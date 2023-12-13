/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:47:24 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/13 16:53:08 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int main(void)
{
	Data	d;
	uintptr_t	ptr;

	std::cout << d.getX() << std::endl;
	std::cout << d.getY() << std::endl;
	std::cout << d.getXPtr() << std::endl;

	ptr = Serialize::serialize(&d);

	return (0);
}