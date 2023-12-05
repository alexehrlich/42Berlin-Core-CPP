/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:23:30 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/05 12:53:16 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	//Animal	animal; //not possible anymore, because its abstract now.
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	j->makeSound();
	i->makeSound();
	//animal.makeSound(); //not possible anymore, because its abstract now.
	
	delete j;//should not create a leak
	delete i;
	
	Animal *animals[4] = { new Dog(), new Cat(), new Dog(), new Cat() };
	
	animals[0]->makeSound();

	std::cout << std::endl;
	Dog d1;
	d1.setIdea(0, "Be nice");
	Dog d2(d1);
	std::cout << "Ideas d2:" << std::endl;
	std::cout << d2.getIdea(0) << std::endl;
	d2.setIdea(1, "smile once a day");
	Dog d3;
	d3 = d2;
	std::cout << "Ideas d3:" << std::endl;
	std::cout << d3.getIdea(0) << std::endl;
	std::cout << d3.getIdea(1) << std::endl;

	for (int i = 0; i < 4; i++)
		delete animals[i];
	return 0;
}