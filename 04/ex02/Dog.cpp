/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:26:35 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/29 16:40:57 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << "Called Dog default constructor" << std::endl;
}

Dog::Dog(const Dog& d)
{
	this->_type = d.getType();
	std::cout << "Called Dog copy constructor" << std::endl;
}

Dog&	Dog::operator=(const Dog& d)
{
	this->_type = d.getType();
	std::cout << "Called Dog copy assignment constructor" << std::endl;
	return (*this);
}

Dog::~Dog()
{
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
