/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:18:15 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/29 16:41:14 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << "Called Cat default constructor" << std::endl;
}

Cat::Cat(const Cat& c)
{
	this->_type = c.getType();
	std::cout << "Called Cat copy constructor" << std::endl;
}

Cat&	Cat::operator=(const Cat& c)
{
	this->_type = c.getType();
	std::cout << "Called Cat copy assignment constructor" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Called Cat destructor" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}

