/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:57:53 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/29 16:32:44 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

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
