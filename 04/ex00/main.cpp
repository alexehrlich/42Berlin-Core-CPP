/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:23:30 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/29 17:01:57 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongCat();
	const Dog* d = new Dog();

	std::cout << j->getType() << " " << std::endl; 
	std::cout << i->getType() << " " << std::endl;
	std::cout << d->getType() << " " << std::endl;
	
	i->makeSound(); //will output the cat sound! 
	j->makeSound();
	k->makeSound(); //is wrong, will output the wrong animal sound
	//j->makeDogThings - does not work, because its of type Animal
	d->makeSound();
	d->makeDogThings();
	meta->makeSound();
	
	delete meta;
	delete j;
	delete i;
	delete d;
	delete k;
	return 0;
}