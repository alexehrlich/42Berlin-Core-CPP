/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:10:31 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/13 15:53:39 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cfloat>

class ScalarConverter
{
	public:
		static void	convert(std::string& literal);

	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& c);
		ScalarConverter&	operator=(const ScalarConverter& c);
};

#endif