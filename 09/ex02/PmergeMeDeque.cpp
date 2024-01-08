/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:35:50 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/08 11:38:02 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::deque<int>	PmergeMe::_generateJacobsthalDeque(int n) {
	std::deque<int> jacobsthalSeq;

	// First two terms of Jacobsthal sequence
	jacobsthalSeq.push_back(0);
	jacobsthalSeq.push_back(1);

	// Generate the Jacobsthal sequence up to the given limit
	for (int i = 2; i <= n; ++i) {
		int current = jacobsthalSeq[i - 1] + 2 * jacobsthalSeq[i - 2];
		jacobsthalSeq.push_back(current);
	}
	return jacobsthalSeq;
}

std::deque<std::pair<int, int> >	PmergeMe::_makeDequePairs()
{
	std::deque<std::pair<int, int> >	_pairedDeque;
	std::deque<int>::iterator			it = _unsortedDeque.begin();
	while(it != _unsortedDeque.end())
	{
		int	first = *it;
		if (++it != _unsortedDeque.end())
		{
			_pairedDeque.push_back(std::make_pair(first, *it));
			it++;
		}
		else
			_struggler = _unsortedDeque.back();
	}
	return (_pairedDeque);
}

void	PmergeMe::_sortDequePairs(std::deque<std::pair<int, int> >& pairDeque)
{
	std::deque<std::pair<int, int> >::iterator it;
	for (it = pairDeque.begin(); it != pairDeque.end(); ++it)
	{
		if (it->first < it->second)
		{
			//f=4, s=5
			it->first = it->first + it->second; //f= 4 + 5 = 9
			it->second = it->first - it->second; //s = 9 - 5 = 4
			it->first = it->first - it->second; // f = 9 - 4 = 5
		}
	}
}

// utils function for merge sort
static void	mergeDeque(std::deque<std::pair<int, int> >& deque, int left, int middle, int right) {
	int n1 = middle - left + 1;
	int n2 = right - middle;

	// Create temporary dequetors
	std::deque<std::pair<int, int> > leftHalf(n1);
	std::deque<std::pair<int, int> > rightHalf(n2);

	// Copy data to temporary dequetors leftHalf[] and rightHalf[]
	for (int i = 0; i < n1; i++)
		leftHalf[i] = deque[left + i];
	for (int j = 0; j < n2; j++)
		rightHalf[j] = deque[middle + 1 + j];

	// Merge the temporary dequetors back into deque[left...right]
	int i = 0;
	int j = 0;
	int k = left;
	while (i < n1 && j < n2) {
		if (leftHalf[i].first <= rightHalf[j].first) {
			deque[k] = leftHalf[i];
			i++;
		} else {
			deque[k] = rightHalf[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of leftHalf[], if there are any
	while (i < n1) {
		deque[k] = leftHalf[i];
		i++;
		k++;
	}

	// Copy the remaining elements of rightHalf[], if there are any
	while (j < n2) {
		deque[k] = rightHalf[j];
		j++;
		k++;
	}
}

void	PmergeMe::_mergeSort(std::deque<std::pair<int, int> >& deque, int left, int right) {
	if (left < right) {
		// Same as (left+right)/2, but avoids overflow for large left and right
		int middle = left + (right - left) / 2;

		// Sort first and second halves
		_mergeSort(deque, left, middle);
		_mergeSort(deque, middle + 1, right);

		// Merge the sorted halves
		mergeDeque(deque, left, middle, right);
	}
}

void insertIntoSortedDeque(std::deque<int>& sortedDeque, int newNumber) {
	std::deque<int>::iterator it = sortedDeque.begin();

	// Find the position to insert the new number
	while (it != sortedDeque.end() && *it < newNumber) {
		++it;
	}

	// Insert the new number at the found position
	sortedDeque.insert(it, newNumber);
}

void	PmergeMe::sortDeque()
{
	_startTimeDeque = clock();
	if (_isSorted())
		return ;
	if (_unsortedDeque.size() == 2)
	{
		_sortedDeque.push_back(_unsortedDeque.back());
		_sortedDeque.push_back(_unsortedDeque.front());
		return ;
	}
	std::deque<std::pair<int, int> >	pairs = _makeDequePairs();
	_sortDequePairs(pairs);
	_mergeSort(pairs, 0, pairs.size() - 1);
	_sortedDeque.push_back(pairs.front().second);
	std::deque<std::pair<int, int> >::iterator it;
	for (it = pairs.begin(); it != pairs.end(); ++it)
		_sortedDeque.push_back(it->first);
	std::deque<std::pair<int, int> >::iterator it1 = pairs.begin();
	while(it1 != pairs.end())
		insertIntoSortedDeque(_sortedDeque, (++it1)->second);
	if (_struggler != -1)
		insertIntoSortedDeque(_sortedDeque, _struggler);
	_endTimeDeque = clock();
}

//Printing

//utils function to print
void	PmergeMe::_printDeque(std::deque<int>& deque)
{
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
