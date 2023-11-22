/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:54:56 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/13 15:38:55 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
    public:
        Fixed& operator=(const Fixed& rhs);
        Fixed(Fixed& f);
        Fixed();
        ~Fixed();
        
        int     getRawBits();
        void    setRawBits(int value);

    private:
        int                 numberValue;
        static const int    fractionalBits = 8;
};

#endif