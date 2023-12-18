/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:27:12 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/18 10:37:16 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	printElement(const T& elem)
{
	std::cout << elem << std::endl;
}

template <typename T>
void	squareElement(T& elem)
{
	elem *= elem;
}

template <typename T, typename F>
void	iter(T *arr, size_t size, F f)
{
	for (size_t i = 0; i < size; i++)
	{
		f(arr[i]);
	}
}

#endif