/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:54:10 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/28 10:55:30 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main( void )
{
	Point	a(0.0f, 0.0f);
	Point	b(0.0f, 10.0f);
	Point	c(10.0f, 0.0f);
	Point	p(1.0f, 2.0f);
	bool	result;

	result = bsp(a, b, c, p);
	if (result == true)
		std::cout << "Point in triangle" << std::endl;
	else
		std::cout << "Point NOT in triangle" << std::endl;
	return 0;
}