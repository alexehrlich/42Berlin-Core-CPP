/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:50:03 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/03 19:09:58 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "TOP: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);
	std::cout << "TOP: " << mstack.top() << std::endl;
	MutantStack<int>::iterator it = mstack.begin(); MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) 
	{
		std::cout << "Element: " << *it << std::endl;
		++it;
	}

	std::cout << "\nCopied Stack" << std::endl;
	MutantStack<int> cs(mstack);
	MutantStack<int>::iterator it1 = cs.begin(); MutantStack<int>::iterator ite1 = cs.end();
	while (it1 != ite1) 
	{
		std::cout << "Element: " << *it1 << std::endl;
		++it1;
	}

	std::cout << "\nCopied assigned Stack" << std::endl;
	MutantStack<int> cas(mstack);
	MutantStack<int>::iterator it2 = cas.begin(); MutantStack<int>::iterator ite2 = cas.end();
	while (it2 != ite2) 
	{
		std::cout << "Element: " << *it2 << std::endl;
		++it2;
	}

	std::stack<int> ns(mstack);
	std::cout << "\nNormal Stack initialized with mutant stack:" << std::endl;
	std::cout << "Size: " << ns.size() << std::endl;
	std::cout << "Top: " << ns.top() << std::endl;
	return 0;
}
