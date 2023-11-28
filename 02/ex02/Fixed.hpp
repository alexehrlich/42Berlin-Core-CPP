/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:54:56 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/28 11:00:05 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
	public:
		Fixed&	operator=(const Fixed& rhs);
		bool	operator>(const Fixed& rhs) const;
		bool	operator<(const Fixed& rhs) const;
		bool	operator>=(const Fixed& rhs) const;
		bool	operator<=(const Fixed& rhs) const;
		bool	operator==(const Fixed& rhs) const;
		bool	operator!=(const Fixed& rhs) const;
		Fixed	operator+(const Fixed& rhs) const;
		Fixed	operator-(const Fixed& rhs) const;
		Fixed	operator*(const Fixed& rhs) const;
		Fixed	operator/(const Fixed& rhs) const;
		Fixed	operator++();
		Fixed	operator++(int);
		Fixed	operator--();
		Fixed	operator--(int);
		Fixed(const Fixed& f);
		Fixed(const int i);
		Fixed(const float f);
		Fixed();
		~Fixed();
		
		int		getRawBits() const;
		void	setRawBits(int value);
		int		toInt() const;
		float	toFloat() const;
		static	Fixed&	min(Fixed& f1, Fixed& f2);
		static	Fixed&	max(Fixed& f1, Fixed& f2);
		static	const Fixed&	min(const Fixed& f1, const Fixed& f2);
		static	const Fixed&	max(const Fixed& f1, const Fixed& f2);
		
	private:
		int					_numberValue;
		static const int	_fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif