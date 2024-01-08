/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:33:57 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/08 17:42:23 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array(): _elements(NULL), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int size): _elements(new T[size]), _size(size) {}

template<typename T>
Array<T>::Array(const Array& a)
{
	if (this == &a)
		return ;
	_size = a.size();
	_elements = new T[a.size()];
	for (unsigned int i = 0; i < a.size(); i++)
		_elements[i] = a._elements[i];
}

template<typename T>
Array<T>&	Array<T>::operator=(const Array& a)
{
	if (this == &a)
		return (*this);
	if (_elements)
		delete [] _elements;
	_size = a.size();
	_elements = new T[a.size()];
	for (unsigned int i = 0; i < a.size(); i++)
		_elements[i] = a._elements[i];
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	if (_elements)
		delete [] _elements;
}

template<typename T>
T&	Array<T>::operator[](unsigned int idx) const
{
	
	if (!_elements)
		throw EmptyArrayException();
	if (idx >= this->_size)
		throw OutOfBoundException();
	return _elements[idx];
}

template<typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}
