/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:35:57 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/13 16:50:35 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(): _x(10), _y(0.23), _xPtr(&_x) {}

Data::~Data() {}

Data::Data(const Data& d): _x(d._x), _y(d._y), _xPtr(&_x) {}

Data&	Data::operator=(const Data& d)
{
	if (&d == this)
		return (*this);
	_x = d._x;
	_y = d._y;
	return (*this);
}

int		Data::getX() const {return _x;}
float	Data::getY() const {return _y;}
int		*Data::getXPtr() const {return _xPtr;}
