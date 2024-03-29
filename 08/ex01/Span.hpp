/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:09:24 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/09 08:51:24 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>
# include <list>
# include <iostream>

class Span
{
	public:
		Span(unsigned int N);
		~Span();

		void	addNumber(int n);
		void	addNumberRange(std::list<int>::iterator begin, std::list<int>::iterator end);
		int		shortestSpan() const;
		int		longestSpan() const;
		int		getSize() const;
		int		at(unsigned int idx) const;

	private:
		Span();
		Span(const Span& s);
		Span&	operator=(const Span& s);

		std::vector<int>	_numbers;

		class SpanFullException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NoSpanException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
