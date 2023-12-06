/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:22:42 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/06 14:56:45 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& b): _name(b._name)
{
	if (this == &b)
		return ;
	_grade = b._grade;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade = grade;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& b)
{
	_grade = b._grade;
	return (*this);
}

const std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::increaseGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade++;
}

void	Bureaucrat::decreaseGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade--;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destroyed " << _name << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade: " << b.getGrade() << std::endl;
	return (os);
}
