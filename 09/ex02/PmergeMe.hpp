/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:24:31 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/08 15:47:47 by aehrlich         ###   ########.fr       */
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
# include <ctime>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();

		void	readInList(int argc, char **argv);
		void	sortVector();
		void	sortDeque();
		void	printResults();

	private:
		int									_struggler;

		std::vector<int>					_unsortedVec;
		std::vector<int>					_sortedVec;
		clock_t								_startTimeVec;
		clock_t								_endTimeVec;
		bool								_isSortedVector();
		std::vector<std::pair<int, int> >	_makeVectorPairs();
		void								_sortVectorPairs(std::vector<std::pair<int, int> >& pairVec);
		void								_mergeSort(std::vector<std::pair<int, int> >& vec, int left, int right);
		void								_printVector(std::vector<int>& vec);
		void								_generateNextJacobsthalNumberVec(std::vector<int>& sequence);
		std::vector<int>					_generateInsertionOrderVec(int containerSize);

		std::deque<int>						_unsortedDeque;
		std::deque<int>						_sortedDeque;
		clock_t								_startTimeDeque;
		clock_t								_endTimeDeque;
		bool								_isSortedDeque();
		std::deque<std::pair<int, int> >	_makeDequePairs();
		void								_sortDequePairs(std::deque<std::pair<int, int> >& pairDeque);
		void								_mergeSort(std::deque<std::pair<int, int> >& deque, int left, int right);
		void								_printDeque(std::deque<int>& deque);
		void								_generateNextJacobsthalNumberDeque(std::deque<int>& sequence);
		std::deque<int>						_generateInsertionOrderDeque(int containerSize);


	class InputErrorException: public std::exception
	{
		virtual const char*	what() const throw()
		{
			return ("Error in Input list.");
		};
	};
};

#endif
