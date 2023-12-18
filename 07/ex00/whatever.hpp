/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FuncTemplates.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:27:12 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/18 09:49:49 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTEMPLATES_HPP
# define FUNCTEMPLATES_HPP

template <typename T>
void	swap(T& lhs, T& rhs)
{
	T	temp = rhs;
	rhs = lhs;
	lhs = temp;
}

template <typename T>
T		min(const T& lhs, const T& rhs)
{
	return (lhs < rhs ? lhs : rhs);
}

template <typename T>
T		max(const T& lhs, const T& rhs)
{
	return (lhs > rhs ? lhs : rhs);
}


#endif