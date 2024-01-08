/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:27:12 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/08 17:07:02 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTEMPLATES_HPP
# define FUNCTEMPLATES_HPP

namespace myfuncs
{	
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
}


#endif