/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:25:15 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/05 11:07:21 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_materiasToLearn[i] = NULL;
	std::cout << "Default MateriaSource was created" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_materiasToLearn[i])
			delete _materiasToLearn[i];
	}
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materiasToLearn[i] == NULL)
		{
			_materiasToLearn[i] = m;
			std::cout << "MateriaSoruce learned " << m->getType() << " to index: " << i << std::endl;
			return ;
		}
	}
	std::cout << "MateriaSource has no capacity to learn" << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materiasToLearn[i]->getType() == type)
		{
			std::cout << "MateriaSource learned " << type << " and returns a new one" << std::endl;
			return (_materiasToLearn[i]->clone());
		}
	}
	std::cout << "MateriaSource did not learn " << type << std::endl;
	return (NULL);
}