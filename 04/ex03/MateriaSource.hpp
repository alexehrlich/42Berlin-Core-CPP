/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:23:58 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/04 18:32:42 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	
private:
	AMateria*	_materiasToLearn[4];

public:
	MateriaSource();
	~MateriaSource();

	void		learnMateria(AMateria* m);
	AMateria*	createMateria(std::string const & type);
};

#endif