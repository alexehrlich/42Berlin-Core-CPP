/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:34:39 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/11 17:06:35 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request", target, 72, 45)
{
	#ifdef PRINT_MSGS
		std::cout << "Created Robotomy Request Form" << std::endl;
	#endif
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& f): AForm("Robotomy Request", f._target, 72, 45)
{
	#ifdef PRINT_MSGS
		std::cout << "Created Robotomy Request Form" << std::endl;
	#endif
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& f)
{
	if (this != &f) {}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	#ifdef PRINT_MSGS
		std::cout << "Destroyed Roboty Request Form" << std::endl;
	#endif
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	AForm::_execute(executor);
	std::cout << "DRILLLLLL" << std::endl;
	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << _target <<" has been robotomized successfully" << std::endl;
	else
		std::cout << _target <<" failed to be robotomized" << std::endl;
}
