/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:41:17 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/27 14:47:49 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/*		CONSTURCTOR		*/
Fixed::Fixed(const Fixed& f)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(f.getRawBits());
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_numberValue = 0;
}

Fixed::Fixed(const int i)
{
	_numberValue = i << _fractionalBits;
}

Fixed::Fixed(const float f)
{
	_numberValue = (int)roundf(f * (float)(1 << _fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/*		MEMBER FUNCTIONS	*/
void Fixed::setRawBits(int value)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_numberValue = value;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_numberValue);
}

int	Fixed::toInt() const
{
	return (_numberValue >> _fractionalBits);
}

float	Fixed::toFloat() const
{
	return ((float)(_numberValue / (float)(1 << _fractionalBits)));
}

/*		OPERATOR OVERLOAD	*/
Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment constructor called" << std::endl;
	this->setRawBits(rhs.getRawBits());
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return os;
}
