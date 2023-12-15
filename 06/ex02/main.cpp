/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:47:24 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/15 11:40:33 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
	public:
		virtual	~Base() {};
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

class D: public Base {};

Base	*generate(void)
{
	std::srand(time(NULL));
	switch (std::rand() % 3)
	{
	case 0:
		std::cout << "Created A" << std::endl;
		return new A();
	case 1:
		std::cout << "Created B" << std::endl;
		return new B();
	case 2:
		std::cout << "Created C" << std::endl;
		return new C();
	default:
		return (NULL);
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unidentifiable" << std::endl;
}

void	identify(Base& b)
{
	try
	{
		A derived = dynamic_cast<A&>(b);
		std::cout << "A" << std::endl;
	}
	catch(std::exception e)
	{
		try
		{
			B derived = dynamic_cast<B&>(b);
			std::cout << "B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C derived = dynamic_cast<C&>(b);
				std::cout << "C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "Unidentifiable" << std::endl;
			}
		}
		
	}
}

int main(void)
{
	Base *base = new Base();
	Base *d = new D();
	Base *rand = generate();
	std::cout << std::endl;

	identify(*base);
	identify(base);
	std::cout << std::endl;
	identify(d);
	identify(*d);
	std::cout << std::endl;
	identify(rand);
	identify(*rand);
	return (0);
}
