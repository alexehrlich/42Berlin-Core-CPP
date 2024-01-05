/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:41:54 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/05 11:38:54 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}


bool isOperator(const char token) {
	return token == '+' || token == '-' || token == '*' || token == '/';
}


int	RPN::calculate(std::string input)
{
	std::istringstream iss(input);
	std::stack<int> _storage;

	std::string token;
	while (iss >> token)
	{
		if (token.size() != 1)
			throw RPN::CalculationException();
		if (isdigit(token[0]))
			_storage.push(token[0] - '0');
		else if (isOperator(token[0]))
		{
			if (_storage.size() < 2) //if two operands follows, the stack is empty. Gets caught here
				throw RPN::CalculationException();
			int operand2 = _storage.top();
			_storage.pop();

			int operand1 = _storage.top();
			_storage.pop();

			// Perform the operation and push the result back onto the stack
			switch (token[0])
			{
				case '+':
					_storage.push(operand1 + operand2);
					break;
				case '-':
					_storage.push(operand1 - operand2);
					break;
				case '*':
					_storage.push(operand1 * operand2);
					break;
				case '/':
					if (operand2 == 0) 
						throw RPN::CalculationException();
					_storage.push(operand1 / operand2);
					break;
				default:
					throw RPN::CalculationException();
			}
		} else
			throw RPN::CalculationException();
	}
	if (_storage.size() == 1) {
		return _storage.top();
	} else
		throw RPN::CalculationException();
}