/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:41:17 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/27 17:08:21 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/*		CONSTURCTOR		*/
Fixed::Fixed(const Fixed& f)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(f.getRawBits());
}

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
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
	//std::cout << "Destructor called" << std::endl;
}

/*		MEMBER FUNCTIONS	*/
void Fixed::setRawBits(int value)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_numberValue = value;
}

int Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called" << std::endl;
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

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1._numberValue > f2._numberValue)
		return (f2);
	return (f1);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1._numberValue > f2._numberValue)
		return (f1);
	return (f2);
}
const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1._numberValue > f2._numberValue)
		return (f2);
	return (f1);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1._numberValue > f2._numberValue)
		return (f1);
	return (f2);
}
		
/*		OPERATOR OVERLOAD	*/
Fixed& Fixed::operator=(const Fixed& rhs)
{
	//std::cout << "Copy assignment constructor called" << std::endl;
	this->setRawBits(rhs.getRawBits());
	return (*this);
}

bool	Fixed::operator>(const Fixed& rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed& rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed& rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed& rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed& rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed& rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}
Fixed	Fixed::operator*(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed	Fixed::operator++()
{
	++(this->_numberValue);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	++(this->_numberValue);
	return (temp);
}

Fixed	Fixed::operator--()
{
	--(this->_numberValue);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	--(this->_numberValue);
	return (temp);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return os;
}
