/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:02:02 by aehrlich          #+#    #+#             */
/*   Updated: 2023/08/01 16:03:11 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "PhoneBook.hpp"
#include "UserInterface.hpp"

int	main()
{
	PhoneBook		pb;
	UserInterface	ui;
	Contact			tempContact;
	std::string		inputString;

	ui.introduction();
	while (std::getline(std::cin, inputString) && inputString != "EXIT")
	{
		if (inputString == "ADD")
			pb.addContact(ui.addRoutine());
		else if (inputString == "SEARCH")
			ui.searchRoutine(pb);
		else
			std::cout << "ERROR:" <<"No valid option." << std::endl;
		std::cout << "Choose between ADD, SEARCH and EXIT." << std::endl;
	}
	return (EXIT_SUCCESS);
}
