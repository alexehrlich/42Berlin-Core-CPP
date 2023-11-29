/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:18:15 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/29 16:41:14 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
	std::cout << "Called WrongCat default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& c)
{
	this->_type = c.getType();
	std::cout << "Called WrongCat copy constructor" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& c)
{
	this->_type = c.getType();
	std::cout << "Called WrongCat copy assignment constructor" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "Called WrongCat destructor" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Wrong Meow" << std::endl;
}

