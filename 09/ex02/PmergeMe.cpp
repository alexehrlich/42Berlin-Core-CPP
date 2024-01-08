/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:33:30 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/08 16:06:54 by aehrlich         ###   ########.fr       */
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

void	PmergeMe::printResults()
{
	std::cout << "Before:\t"; _printVector(_unsortedVec);
	std::cout << "After:\t"; _printVector(_sortedVec);
	std::cout << "After:\t"; _printDeque(_sortedDeque);
	double vectorTime = static_cast<double>(_endTimeVec - _startTimeVec) / CLOCKS_PER_SEC * 1000000.0;
	double dequeTime = static_cast<double>(_endTimeDeque - _startTimeDeque) / CLOCKS_PER_SEC * 1000000.0;
	
	std::cout << "Time to process a range of " << _unsortedVec.size() << " elements with std::vector<int>:\t" << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _unsortedVec.size() << " elements with std::deque<int> :\t" << dequeTime << " us" << std::endl;
}
