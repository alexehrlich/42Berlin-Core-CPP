/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:34:39 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/11 15:18:26 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation", target, 145, 137)
{
	#ifdef PRINT_MSGS
		std::cout << "Created Shrubbery Creation Form" << std::endl;
	#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& f): AForm("Shrubbery Creation", f._target, 145, 137)
{
	#ifdef PRINT_MSGS
		std::cout << "Created Shrubbery Creation Form" << std::endl;
	#endif
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& f)
{
	if (this != &f) {}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	#ifdef PRINT_MSGS
		std::cout << "Destroyed Roboty Request Form" << std::endl;
	#endif
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	try
	{
		AForm::_execute(executor);
		std::ofstream	outfile;
		outfile.open((_target + "_shrubbery").c_str());
		if (outfile.fail())
			std::cout << "Could not create file" << std::endl;
		else
		{
			outfile << "      _-_" << std::endl;
			outfile << "   /~~   ~~\\" << std::endl;
			outfile << "/~~         ~~\\" << std::endl;
			outfile << "{              }" << std::endl;
			outfile << "\\  _-     -_  /" << std::endl;
			outfile << "  ~  \\\\ //  ~" << std::endl;
			outfile << "- -   | | _- _" << std::endl;
			outfile << " _ -  | |   -_" << std::endl;
			outfile << "     // \\\\" << std::endl;
			outfile.close();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
