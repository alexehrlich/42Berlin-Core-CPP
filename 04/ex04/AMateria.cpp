/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:46:36 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/04 18:15:55 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const & type)
{
	_type = type;
}

AMateria::AMateria(const AMateria& src)
{
	//Copying type of Materia doesnt make sense
}

AMateria&	AMateria::operator=(const AMateria& src)
{
	//Copying type of Materia doesnt make sense
}

AMateria::~AMateria()
{
	std::cout << "AMateria destroyed" << std::endl;
}

std::string	const & AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "Materia " << getType() << " is used on target " << target.getName() << std::endl;
}