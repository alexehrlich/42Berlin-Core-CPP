/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:18:15 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/05 12:50:40 by aehrlich         ###   ########.fr       */
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
	_brain = new Brain();
	*_brain = *c._brain;
	std::cout << "Called Cat copy constructor" << std::endl;
}

Cat&	Cat::operator=(const Cat& c)
{
	this->_type = c.getType();
	if (this->_brain)
		delete this->_brain;
	_brain = new Brain();
	*_brain = *c._brain;
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

void	Cat::setIdea(int idx, std::string idea)
{
	if (idx >= 0 && idx < 100)
		_brain->ideas[idx] = idea;
}

std::string	Cat::getIdea(int idx)
{
	if (idx >= 0 && idx < 100)
		return (_brain->ideas[idx]);
	return "";
}