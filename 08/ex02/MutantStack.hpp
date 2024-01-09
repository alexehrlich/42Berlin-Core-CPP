/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:39:43 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/09 18:10:50 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>() : std::stack<T>() {};
		MutantStack<T> (MutantStack const &src) : std::stack<T>(src) {};
		MutantStack<T> &operator=(MutantStack const &rhs) {
			if (this != &rhs)
				this->c = rhs.c;
			return (*this);
		}
		~MutantStack<T>() {};

		//Typedefs are used to make the code more readable but then als
		//typename is required in order to use the typedef as a type
		//So the typename keyword is used to tell the compiler that std::stack<T>::container_type::iterator refers to a type
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack<T>::iterator begin (void) {
			return (this->c.begin());
		}
		MutantStack<T>::iterator end (void){
			return (this->c.end());
		}

		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
		MutantStack<T>::const_iterator begin (void) const {
			return (this->c.begin());
		}
		MutantStack<T>::const_iterator end (void) const {
			return (this->c.end());
		}

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		MutantStack<T>::reverse_iterator rbegin (void) {
			return (this->c.rbegin());
		}
		MutantStack<T>::reverse_iterator rend (void) {
			return (this->c.rend());
		}

		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;
		MutantStack<T>::const_reverse_iterator rbegin (void) const {
			return (this->c.rbegin());
		}
		MutantStack<T>::const_reverse_iterator rend (void) const {
			return (this->c.rend());
		}
};
#endif