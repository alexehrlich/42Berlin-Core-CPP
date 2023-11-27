/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:54:56 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/27 14:43:29 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
	public:
		Fixed& operator=(const Fixed& rhs);
		Fixed(const Fixed& f);
		Fixed(const int i);
		Fixed(const float f);
		Fixed();
		~Fixed();
		
		int		getRawBits() const;
		void	setRawBits(int value);
		int		toInt() const;
		float	toFloat() const;

	private:
		int					_numberValue;
		static const int	_fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif