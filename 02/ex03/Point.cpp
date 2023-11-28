/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:04:17 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/28 09:02:26 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*		CONSTRUCOR - DESTRUCOR		*/
Point::Point() : _x(Fixed(0)), _y(Fixed(0)) {}
Point::Point(const float x, const float y): _x(Fixed(x)), _y(Fixed(y)) {}
Point::Point(const Point& p): _x(Fixed(p.getX())), _y(Fixed(p.getY())) {}
Point::~Point() {}

Fixed	Point::getX() const { return this->_x; }
Fixed	Point::getY() const { return this->_y; }

Point&	Point::operator=(const Point& p)
{
	if (this != &p)
	{
		(Fixed) this->_x = p.getX();
		(Fixed) this->_y = p.getY();
	}
	return (*this);
}
