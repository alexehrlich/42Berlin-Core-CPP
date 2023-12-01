/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:23:30 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/01 10:49:02 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	j->makeSound();
	i->makeSound();
	
	delete j;//should not create a leak
	delete i;
	
	Animal *animals[4] = { new Dog(), new Cat(), new Dog(), new Cat() };
	
	animals[0]->makeSound();

	for (int i = 0; i < 4; i++)
		delete animals[i];
	return 0;
}