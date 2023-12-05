/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:05:07 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/05 11:45:06 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->_type = "Animal";
	std::cout << "Called Animal default constructor" << std::endl;
}

Animal::Animal(const Animal& a): _type(a.getType())
{
	std::cout << "Called Animal copy constructor" << std::endl;
}

Animal&	Animal::operator=(const Animal& a)
{
	if (this != &a)
	{
		this->_type = a.getType();
		std::cout << "Called Animal copy assignment constructor" << std::endl;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Called Animal destructor" << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "Abstract animal sound" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}

