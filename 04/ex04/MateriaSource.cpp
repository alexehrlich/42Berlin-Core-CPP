/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:25:15 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/04 18:40:52 by aehrlich         ###   ########.fr       */
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
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materiasToLearn[i] == NULL)
			_materiasToLearn[i] = m;
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materiasToLearn[i]->getType() == type)
			return (_materiasToLearn[i]->clone());
	}
	return (NULL);
}