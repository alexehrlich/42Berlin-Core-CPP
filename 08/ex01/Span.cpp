/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:18:03 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/10 08:40:39 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N)
{
	_numbers.reserve(N);
	std::cout << "Created Span with capacity " << _numbers.capacity() << std::endl;
}

Span::~Span() {}

void	Span::addNumberRange(std::list<int>::iterator begin, std::list<int>::iterator end)
{
	while (begin != end)
	{
		addNumber(*begin);
		begin++;
	}
}

void	Span::addNumber(int n)
{
	if (_numbers.size() == _numbers.capacity())
		throw SpanFullException();
	if (_numbers.empty())
		_numbers.insert(_numbers.begin(), n);
	else
	{
		for (std::vector<int>::iterator	it = _numbers.begin(); it != _numbers.end(); it++)
		{
			if (n <= *it)
			{
				_numbers.insert(it, n);
				return ;
			}
		}
		_numbers.insert(_numbers.end(), n);
	}
}

int	Span::shortestSpan() const
{
	if (_numbers.size() <= 1)
		throw NoSpanException();

	int minDifference = std::abs(_numbers[0] - _numbers[1]);
	for (std::vector<int>::const_iterator it1 = _numbers.begin(); it1 != _numbers.end(); ++it1) {
		for (std::vector<int>::const_iterator it2 = it1 + 1; it2 != _numbers.end(); ++it2) {
			int currentDifference = std::abs(*it1 - *it2);
			if (currentDifference < minDifference) {
				minDifference = currentDifference;
			}
		}
	}
	return minDifference;
}

int	Span::longestSpan() const
{
	return (std::abs(_numbers.back() - _numbers.front()));
}

int	Span::getSize() const
{
	return (_numbers.size());
}

int	Span::at(unsigned int idx) const
{
	return (_numbers.at(idx));
}

const char*	Span::SpanFullException::what() const throw()
{
	return ("Cannot add number: Span is already full.");
}

const char*	Span::NoSpanException::what() const throw()
{
	return ("Cannot calculate span: Less that two numbers.");
}

