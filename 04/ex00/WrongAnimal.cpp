/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:05:07 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/29 16:53:59 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->_type = "WrongAnimal";
	std::cout << "Called WrongAnimal default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& a): _type(a.getType())
{
	std::cout << "Called WrongAnimal copy constructor" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& a)
{
	this->_type = a.getType();
	std::cout << "Called WrongAnimal copy assignment constructor" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Called WrongAnimal destructor" << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Wrong animal sound" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}

