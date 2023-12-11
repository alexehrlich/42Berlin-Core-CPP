/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:33:54 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/11 16:19:22 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	#ifdef PRINT_MSGS
		std::cout << "Created intern" << std::endl;
	#endif
}

Intern::~Intern()
{
	#ifdef PRINT_MSGS
		std::cout << "Destroyed intern" << std::endl;
	#endif
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	AForm*		form;
	std::string	forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int			idx = 0;

	while (idx < 3 && name != forms[idx])
		idx++;
	switch (idx)
	{
		case (0):
			form = new ShrubberyCreationForm(target);
			break;
		case (1):
			form = new RobotomyRequestForm(target);
			break;
		case (2):
			form = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "Creation faild: no form with name: " << name << std::endl;
			return (NULL);
	}
	std::cout << "Intern creates " << name << std::endl;
	return (form);
}
