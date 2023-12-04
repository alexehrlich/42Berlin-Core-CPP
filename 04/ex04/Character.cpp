/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:13:22 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/04 18:19:02 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(){
	this->_name = "unnamed";
	for (int i = 0; i < 4; i++)
		this->_slots[i] = NULL;
	std::cout << "Default character was born" << std::endl;
}

Character::Character(const Character& src)
{
	this->_name = src._name;
	for (int i = 0; i < 4; i++)
	{
		if (this->_slots[i])
			delete _slots[i];
		this->_slots[i] = src._slots[i]->clone();
	}
	std::cout << "Character was copied" << std::endl;
}

Character::Character(std::string name): _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_slots[i] = NULL;
	std::cout << "Character " << name << " was born" << std::endl;
}

Character&	Character::operator=(const Character& src)
{
	this->_name = src._name;
	for (int i = 0; i < 4; i++)
	{
		if (this->_slots[i])
			delete _slots[i];
		this->_slots[i] = src._slots[i]->clone();
	}
	std::cout << "Character was assigned" << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (this->_slots[i])
			delete _slots[i];
	std::cout << "Character " << _name << " was destroyed" << std::endl;
}

std::string const & Character::getName() const
{
	return this->_name;
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_slots[i] == NULL)
			_slots[i] = m;
	}
}

void	Character::unequip(int idx)
{
	if (_slots[idx])
		_slots[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (_slots[idx])
		_slots[idx]->use(target);
}
