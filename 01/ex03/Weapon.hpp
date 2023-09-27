/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 11:54:53 by aehrlich          #+#    #+#             */
/*   Updated: 2023/09/23 12:14:45 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <string.h>
#include <iostream>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string&	getType()const;
		void				setType(std::string type);

	private:
		std::string	_type;
};
#endif
