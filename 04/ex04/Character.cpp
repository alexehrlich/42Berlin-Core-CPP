/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:13:22 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/05 10:12:46 by aehrlich         ###   ########.fr       */
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
	return (*this);
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
		{
			_slots[i] = m;
			std::cout << _name << " was equipped with " << m->getType() << std::endl;
			return ;
		}
	}
	std::cout << _name <<" could not be equipped" << std::endl;
}

void	Character::unequip(int idx)
{
	if (_slots[idx])
	{
		std::cout << _name << " unequipped at slot " << idx <<": " << _slots[idx]->getType() << std::endl;
		_slots[idx] = NULL;
		return ;
	}
	std::cout << _name <<" could not be unequipped" << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (_slots[idx])
	{
		_slots[idx]->use(target);
		std::cout << _name << " uses " << _slots[idx]->getType() << " on target: " << target.getName() << std::endl;
		return ;
	}
	std::cout << _name << " has nothing to use on this slot index" << std::endl;
}
