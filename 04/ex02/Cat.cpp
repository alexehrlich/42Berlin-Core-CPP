/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:18:15 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/04 18:10:44 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Called Cat default constructor" << std::endl;
}

Cat::Cat(const Cat& c)
{
	this->_type = c.getType();
	delete this->_brain;
	_brain = new Brain();
	for (int i = 0; i < 100; i++)
		_brain[i] = c._brain[i];
	std::cout << "Called Cat copy constructor" << std::endl;
}

Cat&	Cat::operator=(const Cat& c)
{
	this->_type = c.getType();
	delete this->_brain;
	_brain = new Brain();
	for (int i = 0; i < 100; i++)
		_brain[i] = c._brain[i];
	std::cout << "Called Cat copy assignment constructor" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Called Cat destructor" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}

