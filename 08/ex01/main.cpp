/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:50:03 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/10 08:41:33 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <list>

int main() {
	Span sp(10);
	try
	{
		sp.addNumber(6);
		sp.addNumber(-1);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(20);
		sp.addNumber(8);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	for (int i = 0; i < sp.getSize(); i++)
	{
		std::cout << sp.at(i) << std::endl;
	}
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

	std::list<int> l( 10 );
	std::srand( time ( NULL ) );
	std::generate( l.begin(), l.end(), std::rand );
	try
	{
		sp.addNumberRange(l.begin(), l.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	for (int i = 0; i < sp.getSize(); i++)
	{
		std::cout << sp.at(i) << std::endl;
	}
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	return 0;
}
