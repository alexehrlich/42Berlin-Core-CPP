/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:05:07 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/01 09:33:34 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	this->_brain = new Brain();
	this->_type = "AAnimal";
	std::cout << "Called AAnimal default constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal& a): _type(a.getType()), _brain(new Brain())
{
	std::cout << "Called AAnimal copy constructor" << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& a)
{
	if (this != &a)
	{
		delete this->_brain;
		_brain = new Brain();
		this->_type = a.getType();
		std::cout << "Called AAnimal copy assignment constructor" << std::endl;
	}
	return (*this);
}

AAnimal::~AAnimal()
{
	delete _brain;
	std::cout << "Called AAnimal destructor" << std::endl;
}

void	AAnimal::makeSound(void) const
{
	std::cout << "Abstract animal sound" << std::endl;
}

std::string AAnimal::getType(void) const
{
	return (this->_type);
}

