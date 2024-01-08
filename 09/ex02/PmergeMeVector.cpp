/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:34:34 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/08 10:43:40 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>	PmergeMe::_generateJacobsthalVec(int n) {
	std::vector<int> jacobsthalSeq;

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

std::vector<std::pair<int, int> >	PmergeMe::_makeVectorPairs()
{
	std::vector<std::pair<int, int> >	_pairedVec;
	std::vector<int>::iterator			it = _unsortedVec.begin();
	while(it != _unsortedVec.end())
	{
		int	first = *it;
		if (++it != _unsortedVec.end())
		{
			_pairedVec.push_back(std::make_pair(first, *it));
			it++;
		}
		else
			_struggler = _unsortedVec.back();
	}
	return (_pairedVec);
}

void	PmergeMe::_sortVectorPairs(std::vector<std::pair<int, int> >& pairVec)
{
	std::vector<std::pair<int, int> >::iterator it;
	for (it = pairVec.begin(); it != pairVec.end(); ++it)
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
static void	mergeVector(std::vector<std::pair<int, int> >& vec, int left, int middle, int right) {
	int n1 = middle - left + 1;
	int n2 = right - middle;

	// Create temporary vectors
	std::vector<std::pair<int, int> > leftHalf(n1);
	std::vector<std::pair<int, int> > rightHalf(n2);

	// Copy data to temporary vectors leftHalf[] and rightHalf[]
	for (int i = 0; i < n1; i++)
		leftHalf[i] = vec[left + i];
	for (int j = 0; j < n2; j++)
		rightHalf[j] = vec[middle + 1 + j];

	// Merge the temporary vectors back into vec[left...right]
	int i = 0;
	int j = 0;
	int k = left;
	while (i < n1 && j < n2) {
		if (leftHalf[i].first <= rightHalf[j].first) {
			vec[k] = leftHalf[i];
			i++;
		} else {
			vec[k] = rightHalf[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of leftHalf[], if there are any
	while (i < n1) {
		vec[k] = leftHalf[i];
		i++;
		k++;
	}

	// Copy the remaining elements of rightHalf[], if there are any
	while (j < n2) {
		vec[k] = rightHalf[j];
		j++;
		k++;
	}
}

void	PmergeMe::_mergeSort(std::vector<std::pair<int, int> >& vec, int left, int right) {
	if (left < right) {
		// Same as (left+right)/2, but avoids overflow for large left and right
		int middle = left + (right - left) / 2;

		// Sort first and second halves
		_mergeSort(vec, left, middle);
		_mergeSort(vec, middle + 1, right);

		// Merge the sorted halves
		mergeVector(vec, left, middle, right);
	}
}

void	PmergeMe::sortVector()
{
	_startTimeVec = clock();
	if (_isSorted())
		return ;
	if (_unsortedVec.size() == 2)
	{
		_sortedVec.push_back(_unsortedVec.back());
		_sortedVec.push_back(_unsortedVec.front());
		return ;
	}
	std::vector<std::pair<int, int> >	pairs = _makeVectorPairs();
	_sortVectorPairs(pairs);
	_mergeSort(pairs, 0, pairs.size() - 1);
	_sortedVec.push_back(pairs.front().second);
	std::vector<std::pair<int, int> >::iterator it;
	for (it = pairs.begin(); it != pairs.end(); ++it)
		_sortedVec.push_back(it->first);
	std::vector<int>	jacobsthal = _generateJacobsthalVec(pairs.size() - 1);
	_endTimeVec = clock();
}

//Printing

//utils function to print
void	PmergeMe::_printVector(std::vector<int>& vec)
{
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
