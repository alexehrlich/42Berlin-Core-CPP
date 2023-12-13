/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:15:00 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/13 16:20:30 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void	ignoreLastF(std::string& str)
{
	if (str.length() < 2)
		return ;
	if (str == "+inf" || str == "-inf" || str == "inf")
		return ;
	if (str.at(str.length() - 1) == 'f')
		str = str.substr(0, str.length() - 1);
}

static void	printChar(double d)
{
	if (d < 0 || d > 127 || std::isnan(d) || std::isinf(d))
		std::cout << "char:\timpossible" << std::endl;
	else if (d < 33 || d > 126)
		std::cout << "char:\tNon displayable" << std::endl;
	else
	{
		char	c = static_cast<char>(d);
		std::cout << "char:\t'" << c << "'"<< std::endl;
	}
}

static void	printInt(double d)
{
	if (d > std::numeric_limits<int>::max()
		|| d < std::numeric_limits<int>::min()
		|| std::isnan(d) || std::isinf(d))
		std::cout << "int:\timpossible" << std::endl;
	else
	{
		int	i = static_cast<int>(d);
		std::cout << "int:\t" << i << std::endl;
	}
}

static void	printFloat(double d)
{
	if ((d > std::numeric_limits<float>::max()
		|| d < -(std::numeric_limits<float>::max()))
		&& !std::isnan(d) && !std::isinf(d))
		std::cout << "float:\timpossible" << std::endl;
	else
	{
		float	f = static_cast<float>(d);
		std::cout << "float:\t" << f << "f" << std::endl;
	}
}

void	ScalarConverter::convert(std::string& literal)
{
	double	d;
	char	*endptr;

	ignoreLastF(literal);
	d = std::strtod(literal.c_str(), &endptr);
	if (errno == ERANGE || *endptr != '\0' || literal.empty()) {
		std::cout << "char:\timpossible" << std::endl;
		std::cout << "int:\timpossible" << std::endl;
		std::cout << "float:\timpossible" << std::endl;
		std::cout << "double:\timpossible" << std::endl;
	} else {
		printChar(d);
		printInt(d);
		std::cout << std::fixed << std::setprecision(1);
		printFloat(d);
		std::cout << "double:\t" << d <<std::endl;
	}
}
