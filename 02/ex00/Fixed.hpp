/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:54:56 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/27 12:11:26 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed& operator=(const Fixed& rhs);
		Fixed(const Fixed& f);
		Fixed();
		~Fixed();
		
		int		getRawBits() const;
		void	setRawBits(int value);

	private:
		int					_numberValue;
		static const int	_fractionalBits = 8;
};

#endif