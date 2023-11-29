/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:57:53 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/29 16:32:44 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

	class WrongAnimal
	{
		public:
			WrongAnimal();
			WrongAnimal(const WrongAnimal& a);
			virtual			~WrongAnimal();
			WrongAnimal&			operator=(const WrongAnimal& a);

			void	makeSound(void) const;
			std::string		getType(void) const;

		protected:
			std::string	_type;
	};
	
#endif
