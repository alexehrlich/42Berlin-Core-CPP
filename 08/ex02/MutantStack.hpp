/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:39:43 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/03 19:02:37 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator	iterator;
		MutantStack(void);
		~MutantStack(void);
		//MutantStack(const MutantStack& cpy);					//use the Constructor of stack beacuase no new attributes
		//MutantStack<T>&	operator=(const MutantStack& cpy);	//use the Constructor of stack beacuase no new attributes

		iterator	begin(void);
		iterator	end(void);
};

template<typename T>
MutantStack<T>::MutantStack(void) {};

template<typename T>
MutantStack<T>::~MutantStack(void) {};

/* template<typename T>
MutantStack<T>::MutantStack(const MutantStack& cpy)
{
	if (this != &cpy)
		this->operator=(cpy);
};

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack& cpy)
{
	this->operator=(cpy);
	return (*this);
}; */

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return (this->c.begin()); //Pointer to the first element of the underlying container
};

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return (this->c.end()); //Pointer to the last element of the underlying container
};

#endif