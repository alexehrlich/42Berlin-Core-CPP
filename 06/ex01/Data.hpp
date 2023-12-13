/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:32:24 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/13 16:41:04 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

class Data
{
	public:
		Data();
		~Data();
		Data(const Data& d);
		Data&	operator=(const Data& d);

		int		getX() const;
		float	getY() const;
		int*	getXPtr() const;

	private:
		int		_x;
		float	_y;
		int*	_xPtr;
};

#endif
