/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:53:06 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/27 20:14:16 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& p);
		~Point();
		Point&	operator=(const Point& p);

		Fixed	getX() const;
		Fixed	getY() const;

		bool	bsp(Point const a, Point const b, Point const c, Point const point);

	private:
		const Fixed	_x;
		const Fixed	_y;
};

#endif

