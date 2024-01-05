/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:33:49 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/05 11:36:52 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>
# include <cstdlib>
# include <sstream>
# include <cctype>

class RPN
{
	public:
		RPN();
		~RPN();
		RPN(const RPN& rhs);						//Doesnt make sense for a class with only static members
		RPN&		operator=(const RPN& rhs);		//Doesnt make sense for a class with only static members

		static int	calculate(std::string input);

	private:
		static std::stack<int>	_storage;

	class CalculationException: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Error";
			}
	};
};

#endif