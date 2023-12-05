/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:23:30 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/05 11:52:39 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	//AAnimal	animal; //not possible anymore, because its abstract now.
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	j->makeSound();
	i->makeSound();
	//animal.makeSound(); //not possible anymore, because its abstract now.
	
	delete j;//should not create a leak
	delete i;
	
	AAnimal *animals[4] = { new Dog(), new Cat(), new Dog(), new Cat() };
	
	animals[0]->makeSound();

	for (int i = 0; i < 4; i++)
		delete animals[i];
	return 0;
}