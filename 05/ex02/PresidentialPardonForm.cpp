/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:34:39 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/11 15:15:22 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon", target, 25, 5)
{
	#ifdef PRINT_MSGS
		std::cout << "Created Presidential Pardon Form" << std::endl;
	#endif
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& f): AForm("Presidential Pardon", f._target, 25, 5)
{
	#ifdef PRINT_MSGS
		std::cout << "Created Presidential Pardon Form" << std::endl;
	#endif
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& f)
{
	if (this != &f) {}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	#ifdef PRINT_MSGS
		std::cout << "Destroyed Presidential Pardon Form" << std::endl;
	#endif
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	try
	{
		AForm::_execute(executor);
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
