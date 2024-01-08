/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:48:29 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/08 17:40:48 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T> class Array
{
	public:
		Array();
		Array(unsigned int size);
		Array(const Array& a);
		Array&	operator=(const Array& a);
		~Array();;
		
		T&	operator[](unsigned int idx) const;
		unsigned int	size() const;

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

# include "Array.tpp"

#endif
