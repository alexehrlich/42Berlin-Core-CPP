/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:38:28 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/08 17:08:40 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main( void ) 
{
	int a = 2;
	int b = 3;
	myfuncs::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << myfuncs::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << myfuncs::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	myfuncs::swap( c, d );
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << myfuncs::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << myfuncs::max( c, d ) << std::endl;
	return 0; 
}
