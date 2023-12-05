/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:17:12 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/05 12:34:47 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"

	class Cat: public AAnimal
	{
		public:
			Cat();
			Cat(const Cat& a);
			~Cat();
			Cat&		operator=(const Cat& a);

			void		makeSound(void) const;
			void		setIdea(int idx, std::string idea);
			std::string	getIdea(int idx);

		private:
			Brain*	_brain;
	};

#endif
