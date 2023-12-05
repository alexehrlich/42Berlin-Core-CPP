/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:57:53 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/01 10:36:54 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
	public:
		AAnimal();
		AAnimal(const AAnimal& a);
		virtual			~AAnimal();
		AAnimal&			operator=(const AAnimal& a);

		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;

	protected:
		std::string	_type;
};
	
#endif
