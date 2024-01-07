/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:33:30 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/07 18:14:16 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe():_struggler(-1) {}

PmergeMe::~PmergeMe() {}

void	PmergeMe::readInList(int argc, char** argv)
{
	int					number;
	std::istringstream	iss;
	if (argc < 2)
		throw PmergeMe::InputErrorException();
	++argv;
	while (*argv)
	{
		iss.clear();
		iss.str(*argv);
		iss >> number;
		if (number < 0 || std::find(_unsortedVec.begin(), _unsortedVec.end(), number) != _unsortedVec.end())
			throw PmergeMe::InputErrorException();
		_unsortedVec.push_back(number);
		_unsortedDeque.push_back(number);
		argv++;
	}
	if (iss.fail())
		throw PmergeMe::InputErrorException();
}

bool	PmergeMe::_isSorted()
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

void	PmergeMe::sortVector()
{
	//Start timer here
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
	/*std::vector<std::pair<int, int> >::iterator it;
	for (it = pairs.begin(); it != pairs.end(); ++it) {
		std::cout << "(" << it->first << ", " << it->second << ")" << std::endl;
	}
	std::cout << "Struggler: " << _struggler << std::endl; */
}



void	PmergeMe::sortDeque()
{
	//Start timer here
		if (_isSorted())
			return ;
}
