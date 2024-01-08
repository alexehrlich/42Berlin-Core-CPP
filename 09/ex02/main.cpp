/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:52:31 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/08 11:33:54 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	PmergeMe	pm;

	try
	{
		pm.readInList(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cerr << "usage: ./PmergeMe <n1> <n2> . . ." << std::endl;
		return (1);
	}
	pm.sortVector();
	pm.sortDeque();
	pm.printResults();
	return (0);
}
