/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:17:12 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/05 11:45:15 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

	class Cat: public Animal
	{
		public:
			Cat();
			Cat(const Cat& a);
			~Cat();
			Cat&	operator=(const Cat& a);

			void	makeSound(void) const;

		private:
			Brain*	_brain;
	};

#endif
