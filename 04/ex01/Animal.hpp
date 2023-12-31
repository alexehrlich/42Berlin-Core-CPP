/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:57:53 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/05 11:43:46 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

	class Animal
	{
		public:
			Animal();
			Animal(const Animal& a);
			virtual			~Animal();
			Animal&			operator=(const Animal& a);

			virtual void	makeSound(void) const;
			std::string		getType(void) const;

		protected:
			std::string	_type;
	};
	
#endif
