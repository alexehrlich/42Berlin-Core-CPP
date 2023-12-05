/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:26:35 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/05 12:39:35 by aehrlich         ###   ########.fr       */
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
	_brain = new Brain();
	for (int i = 0; i < 100; i++)
		_brain->ideas[i] = d._brain->ideas[i];
	std::cout << "Called Dog copy constructor" << std::endl;
}

Dog&	Dog::operator=(const Dog& d)
{
	this->_type = d.getType();
	if (this->_brain)
		delete this->_brain;
	_brain = new Brain();
	*_brain = *d._brain;
	std::cout << "Called Dog copy assignment constructor" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Called Dog destructor" << std::endl;
	if (this->_brain)
		delete this->_brain;
}

void	Dog::makeSound(void) const
{
	std::cout << "Wuff" << std::endl;
}

void	Dog::makeDogThings( void ) const
{
	std::cout << "Dog things" << std::endl;
}

void	Dog::setIdea(int idx, std::string idea)
{
	if (idx >= 0 && idx < 100)
		_brain->ideas[idx] = idea;
}

std::string	Dog::getIdea(int idx)
{
	if (idx >= 0 && idx < 100)
		return (_brain->ideas[idx]);
	return "";
}