/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:42:08 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/13 16:47:12 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

uintptr_t	Serialize::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serialize::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
