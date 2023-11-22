/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:41:17 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/13 15:52:41 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed& Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignment constructor called" << std::endl;
    this.setRawBits(rhs.getRawBits());
    return (*this);
}

Fixed::Fixed(Fixed& f)
{
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(f.getRawBits());
}

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->numberValue = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int value)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->numberValue = value;
}

int Fixed::getRawBits()
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->numberValue);
}
