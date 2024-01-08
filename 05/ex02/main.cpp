/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:36:49 by aehrlich          #+#    #+#             */
/*   Updated: 2024/01/08 16:41:51 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	try
	{
		Bureaucrat john("John", 146);
		Bureaucrat alex("Alex", 1);
		ShrubberyCreationForm scf("home");
		RobotomyRequestForm rrf("robo");
		try
		{
			scf.execute(alex);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			alex.executeForm(rrf);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			alex.signForm(rrf);
			try
			{
				alex.executeForm(rrf);
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
			scf.beSigned(john);
		}
		catch(const std::exception& e)
		{
			std::cerr << "beSigned() Excpetion: " << e.what() << '\n';
		}
		try
		{
			john.signForm(scf);
		}
		catch(const std::exception& e)
		{
			std::cerr << "signForm() Excpetion: " << e.what() << '\n';
		}
		try
		{
			john.increaseGrade();
			john.signForm(scf);
			john.signForm(scf);
		}
		catch(const std::exception& e)
		{
			std::cerr << "signForm() Excpetion: " << e.what() << '\n';
		}
		try
		{
			alex.executeForm(scf);
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
	return 0;
}
