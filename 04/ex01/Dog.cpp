/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:26:35 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/04 18:09:19 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Called Dog default constructor" << std::endl;
}

Dog::Dog(const Dog& d)
{
	this->_type = d.getType();
	delete this->_brain;
	_brain = new Brain();
	for (int i = 0; i < 100; i++)
		_brain[i] = d._brain[i];
	std::cout << "Called Dog copy constructor" << std::endl;
}

Dog&	Dog::operator=(const Dog& d)
{
	this->_type = d.getType();
	delete this->_brain;
	_brain = new Brain();
	for (int i = 0; i < 100; i++)
		_brain[i] = d._brain[i];
	std::cout << "Called Dog copy assignment constructor" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Called Dog destructor" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Wuff" << std::endl;
}

void	Dog::makeDogThings( void ) const
{
	std::cout << "Dog things" << std::endl;
}
