/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:24:31 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/08 10:41:13 by aehrlich         ###   ########.fr       */
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
		bool								_isSorted();

		std::vector<int>					_unsortedVec;
		std::vector<int>					_sortedVec;
		clock_t								_startTimeVec;
		clock_t								_endTimeVec;
		std::vector<std::pair<int, int> >	_makeVectorPairs();
		void								_sortVectorPairs(std::vector<std::pair<int, int> >& pairVec);
		void								_mergeSort(std::vector<std::pair<int, int> >& vec, int left, int right);
		void								_printVector(std::vector<int>& vec);
		std::vector<int>					_generateJacobsthalVec(int n);

		std::deque<int>						_unsortedDeque;
		std::deque<int>						_sortedDeque;
		clock_t								_startTimeDeque;
		clock_t								_endTimeDeque;
		std::deque<std::pair<int, int> >	_makeDequePairs();
		void								_sortDequePairs(std::deque<std::pair<int, int> >& pairVec);
		void								_mergeSort(std::deque<std::pair<int, int> >& vec, int left, int right);
		void								_printDeque(std::deque<int>& vec);
		std::deque<int>						_generateJacobsthalDeque(int n);

	class InputErrorException: public std::exception
	{
		virtual const char*	what() const throw()
		{
			return ("Error in Input list.");
		};
	};
};

#endif
