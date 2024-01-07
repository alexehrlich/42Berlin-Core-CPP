/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:24:31 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/07 18:12:41 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <sstream>
# include <algorithm>
# include <utility> 

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();

		void	readInList(int argc, char **argv);
		void	sortVector();
		void	sortDeque();

	private:
		int									_struggler;
		bool								_isSorted();

		std::vector<int>					_unsortedVec;
		std::vector<int>					_sortedVec;
		std::vector<std::pair<int, int> >	_makeVectorPairs();
		void								_sortVectorPairs(std::vector<std::pair<int, int> >& pairVec);
		

		std::deque<int>						_unsortedDeque;
		std::deque<int>						_sortedDeque;

	class InputErrorException: public std::exception
	{
		virtual const char*	what() const throw()
		{
			return ("Error in Input list.");
		};
	};
};

#endif
