/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:38:28 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/18 10:37:11 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main( void ) 
{
	int		integers[] = {0, 1, 2, 3, 4};
	float	floats[] = {0.5, 2.0};
	
	::iter(integers, 5, ::printElement<int>);
	::iter(integers, 5, ::squareElement<int>);
	std::cout << std::endl;
	::iter(integers, 5, ::printElement<int>);
	std::cout << std::endl;
	::iter(floats, 2, ::printElement<float>);
	::iter(floats, 2, ::squareElement<float>);
	std::cout << std::endl;
	::iter(floats, 2, ::printElement<float>);
	return 0; 
}
