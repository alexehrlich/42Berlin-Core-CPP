/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:02:06 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/28 10:29:41 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	abs(Fixed f)
{
	if (f < 0)
		return (f * (-1));
	return (f);
}

Fixed	area(Point const k, Point const l, Point const m)
{
	 return ( ( ( k.getX() * ( l.getY() - m.getY() ) ) +
			 ( l.getX() * ( m.getY() - k.getY() ) ) +
			 ( m.getX() * ( k.getY() - l.getY() ) ) ) / 2 );
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	abc(abs(area(a, b, c)));
	Fixed	pbc(abs(area(point, b, c)));
	Fixed	apc(abs(area(a, point, c)));
	Fixed	abp(abs(area(a, b, point)));

	std::cout << "Area ABC: " << abc << std::endl;
	std::cout << "Area PBC: " << pbc << std::endl;
	std::cout << "Area APC: " << apc << std::endl;
	std::cout << "Area ABP: " << abp << std::endl;
	std::cout << "Area Subs: " << pbc + apc + abp << std::endl;
	
	if (pbc == 0 || apc == 0 || abp == 0)
		return (false);
	return (abc == pbc + apc + abp);
}
