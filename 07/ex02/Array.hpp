/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:48:29 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/19 13:34:41 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T> class Array
{
	public:
		Array(): _elements(NULL), _size(0) {}
		
		Array(unsigned int size): _elements(new T[size]), _size(size) {}
		
		Array(const Array& a)
		{
			if (this == &a)
				return ;
			_size = a.size();
			_elements = new T[a.size()];
			for (unsigned int i = 0; i < a.size(); i++)
				_elements[i] = a._elements[i];
		}
		
		Array&	operator=(const Array& a)
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
		
		~Array()
		{
			if (_elements)
				delete [] _elements;
		}
		
		T&	operator[](unsigned int idx) const
		{
			
			if (!_elements)
				throw EmptyArrayException();
			if (idx >= this->_size)
				throw OutOfBoundException();
			return _elements[idx];
		}

		unsigned int	size() const
		{
			return (_size);
		}

		class OutOfBoundException: public std::exception
		{
			public:
				virtual const char * what() const throw(){
					return "Index out of bounds.";
				}
		};

		class EmptyArrayException: public std::exception
		{
			public:
				virtual const char * what() const throw(){
					return "Tried to access empty array";
				}
		};

	private:
		T*				_elements;
		unsigned int	_size;
};

template <typename T>
std::ostream&	operator<<(std::ostream& os, const Array<T>& a)
{
	if (a.size() == 0)
		os << "Tried to print empty arry." << std::endl;
	for (unsigned int i = 0; i < a.size(); i++)
		os << "array[" << i << "]: " << a[i] << std::endl;
	return (os);
}

#endif
