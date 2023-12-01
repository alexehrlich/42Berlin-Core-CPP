/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:11:36 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/01 10:00:43 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Called Brain default constructor" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Called Brain destructor" << std::endl;
}

Brain::Brain(const Brain& b)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = b.ideas[i];
	std::cout << "Called Brain copy constructor" << std::endl;
}

Brain&	Brain::operator=(const Brain& b)
{
	if (this != &b)
		for (int i = 0; i < 100; i++)
			ideas[i] = b.ideas[i];
	std::cout << "Called Brain copy assignment constructor" << std::endl;
	return (*this);
}
