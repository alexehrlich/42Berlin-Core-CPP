/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:22:42 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/11 16:48:34 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*		CONSTRUCTION - DESTRUCTION						*/

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
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& b)
{
	_grade = b._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	#ifdef PRINT_MSG
		std::cout << "Destroyed " << _name << std::endl;
	#endif
}

/*		CUSTOM EXCEPTION							*/
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade cannot be set: Too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade cannot be set: Too low";
}


/*		GETTER										*/
const std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

/*		METHODS						*/
void	Bureaucrat::increaseGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void	Bureaucrat::decreaseGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

void	Bureaucrat::signForm(AForm& f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed Form: " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << f.getName() << ". Reason: " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm& f) const
{
	try
	{
		f.execute(*this);
		std::cout << _name << " executed Form: " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't execute " << f.getName() << ". Reason: " << e.what() << std::endl;
	}
}

/*		OPERATOR OVERLOADS									*/

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade: " << b.getGrade() << std::endl;
	return (os);
}
