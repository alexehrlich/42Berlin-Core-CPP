/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:25:51 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/29 16:34:54 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

	class Dog: public Animal
	{
		public:
			Dog();
			Dog(const Dog& a);
			~Dog();
			Dog&	operator=(const Dog& a);

			void	makeSound(void) const;
			void	makeDogThings( void ) const;
	};

#endif
