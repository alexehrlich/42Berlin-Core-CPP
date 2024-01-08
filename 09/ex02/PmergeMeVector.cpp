/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:34:34 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/08 16:08:10 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


//Printing
void	PmergeMe::_printVector(std::vector<int>& vec)
{
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

bool	PmergeMe::_isSortedVector()
{
	std::vector<int>::iterator	it = _unsortedVec.begin();
	int							current;
	int							next;
	if (_unsortedVec.size() == 1)
		return (true);
	while (it != _unsortedVec.end())
	{
		current = *it;
		next = *(++it);
		if (it != _unsortedVec.end() && current > next)
			return (false);
	}
		
	return (true);
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

void insertIntoSortedVector(std::vector<int>& sortedVec, int newNumber) {
	std::vector<int>::iterator it = sortedVec.begin();

	// Find the position to insert the new number
	while (it != sortedVec.end() && *it < newNumber) {
		++it;
	}

	// Insert the new number at the found position
	sortedVec.insert(it, newNumber);
}

bool	insertionOrderCompleted(std::vector<int> insertionOrderVec, int maxIndex)
{
	int	i = maxIndex;
	
	for (std::vector<int>::iterator it = insertionOrderVec.begin(); it != insertionOrderVec.end(); it++)
		if (*it <= maxIndex)
			i--;
	return (--i == 0);
}

void	PmergeMe::_generateNextJacobsthalNumberVec(std::vector<int>& sequence)
{
	if (sequence.empty())
	{
		sequence.push_back(0);
		sequence.push_back(1);
		sequence.push_back(1);
	}
	// Generate the Jacobsthal sequence up to the given limit
	std::vector<int>::reverse_iterator rit = sequence.rbegin();

	sequence.push_back(*rit + 2 * *(++rit));
}

std::vector<int>	PmergeMe::_generateInsertionOrderVec(int maxIndex)
{
	std::vector<int>	jacobsthalNumberVec;
	std::vector<int>	insertionOrderVec;
	int	lastJN;
	int preLastJN;

	_generateNextJacobsthalNumberVec(jacobsthalNumberVec);									//genertat the numbers 0 1 1 3
	insertionOrderVec.push_back(jacobsthalNumberVec.back());								//push the 3 to the order vector
	while(!insertionOrderCompleted(insertionOrderVec, maxIndex))							//as long the order vector does not contain all necessary idx, create them
	{
		lastJN = jacobsthalNumberVec[jacobsthalNumberVec.size() - 1];
		preLastJN = jacobsthalNumberVec[jacobsthalNumberVec.size() - 2];
		while (--lastJN > preLastJN)														//generate the indexes between the current jacN and the last (excluding the actual ones)
		{
			insertionOrderVec.push_back(lastJN);
			if (insertionOrderCompleted(insertionOrderVec, maxIndex))						//if all indices are there, we are done
				return (insertionOrderVec);
		}
		_generateNextJacobsthalNumberVec(jacobsthalNumberVec);								//generate a new jacN
		insertionOrderVec.push_back(jacobsthalNumberVec.back());							//append it to the Order
	}
	return (insertionOrderVec);
}

void	PmergeMe::sortVector()
{
	_startTimeVec = clock();																//Start the timer for time measurment
	if (_isSortedVector())
	{
		_sortedVec = _unsortedVec;
		_endTimeVec = clock();
		return ;
	}
	if (_unsortedVec.size() == 2)
	{
		_sortedVec.push_back(_unsortedVec.back());
		_sortedVec.push_back(_unsortedVec.front());
		_endTimeVec = clock();
		return ;
	}
	std::vector<std::pair<int, int> >	pairs = _makeVectorPairs();							//Split the vector into pairs of two
	_sortVectorPairs(pairs);																//Sort the pairs within in ascending order
	_mergeSort(pairs, 0, pairs.size() - 1);													//sort the pair container recursively with merge sort
	_sortedVec.push_back(pairs.front().second);												//insert the first element of the pend to the main chain
	std::vector<std::pair<int, int> >::iterator it;
	for (it = pairs.begin(); it != pairs.end(); ++it)										//push the all greater values to the main chain, since they are now sorted
		_sortedVec.push_back(it->first);
	std::vector<int> insertionOrderVec = _generateInsertionOrderVec(pairs.size());			//generate an order to insert the rest of the pending based on jacobsthal numbers
	std::vector<int>::iterator it1;
	for (it1 = insertionOrderVec.begin(); it1 != insertionOrderVec.end(); ++it1)			//insert the pending elements if the jacobsthal value is valid
	{
		if (static_cast<unsigned long>(*it1) <= pairs.size())
			insertIntoSortedVector(_sortedVec, pairs[*it1 - 1].second);
	}
	if (_struggler != -1)																	//if there was a struggler (odd number of elements) insert it at the end
		insertIntoSortedVector(_sortedVec, _struggler);
	_endTimeVec = clock();																	//stop the timer 
}
