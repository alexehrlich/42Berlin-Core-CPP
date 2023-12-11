/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:36:49 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/11 17:27:44 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern	jeff;
	AForm *fail = jeff.makeForm("dsfasdf", "home");
	ShrubberyCreationForm *scf = (ShrubberyCreationForm *)(jeff.makeForm("shrubbery creation", "bli"));
	PresidentialPardonForm *ppf = (PresidentialPardonForm *)(jeff.makeForm("presidential pardon", "bla"));
	RobotomyRequestForm *rrf = (RobotomyRequestForm *)(jeff.makeForm("robotomy request", "blubb"));
	if (!fail)
		std::cout << "FAIL CHECK" << std::endl;
	try
	{
		Bureaucrat john("John", 146);
		Bureaucrat alex("Alex", 1);
		try
		{
			alex.signForm(*ppf);
			try
			{
				alex.executeForm(*ppf);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			alex.executeForm(*scf);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			alex.executeForm(*rrf);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			alex.signForm(*rrf);
			try
			{
				alex.executeForm(*rrf);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		try
		{
			scf->beSigned(john);
		}
		catch(const std::exception& e)
		{
			std::cerr << "beSigned() Excpetion: " << e.what() << '\n';
		}
		try
		{
			john.signForm(*scf);
		}
		catch(const std::exception& e)
		{
			std::cerr << "signForm() Excpetion: " << e.what() << '\n';
		}
		try
		{
			john.increaseGrade();
			john.signForm(*scf);
			john.signForm(*scf);
		}
		catch(const std::exception& e)
		{
			std::cerr << "signForm() Excpetion: " << e.what() << '\n';
		}
		try
		{
			alex.executeForm(*scf);
		}
		catch(const std::exception& e)
		{
			std::cerr << "ULLA" << e.what() << '\n';
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete ppf;
	delete rrf;
	delete scf;
	return 0;
}
