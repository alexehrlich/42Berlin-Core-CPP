/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:31:43 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/08 10:29:09 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*		CONSTRUCTOR - DESTRUCTOR					*/
AForm::AForm(): _sign_grade_req(1), _exec_grade_req(1){}

AForm&	AForm::operator=(const AForm& f)
{
	if (this != &f) {}
	return (*this);
}

AForm::AForm(std::string name, std::string target, int sign_grad_req, int exec_grade_req):
	_target(target), _name(name), _isSigned(false), _sign_grade_req(sign_grad_req), _exec_grade_req (exec_grade_req)
{}

AForm::AForm(const AForm& f):
	_target(f._target), _name(f._name), _isSigned(f._isSigned), _sign_grade_req(f._sign_grade_req), _exec_grade_req (f._exec_grade_req)
{}

AForm::~AForm(){}

/*		GETTER - SETTER								*/
std::string	AForm::getName() const
{
	return (_name);
}

bool	AForm::getSignStatus() const
{
	return (_isSigned);
}

int		AForm::getReqSignGrade() const
{
	return (_sign_grade_req);
}

int		AForm::getReqExecGrade() const
{
	return (_exec_grade_req);
}

std::string	AForm::getTarget() const
{
	return (_target);
}

/*		CUSTOM EXCEPTIONS							*/
const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade to high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade To Low";
}

const char* AForm::AlreadySignedException::what() const throw()
{
	return "Form is already signed";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "Form is not signed yet";
}

/*		METHODS										*/
void	AForm::beSigned(const Bureaucrat& b)
{
	if (this->_isSigned)
		throw AForm::AlreadySignedException();
	if (b.getGrade() > this->getReqSignGrade())
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

void	AForm::_execute(const Bureaucrat& b) const
{
	if (b.getGrade() > this->getReqExecGrade())
		throw AForm::GradeTooLowException();
	if (!this->getSignStatus())
		throw AForm::NotSignedException();
}

/* OPERATOR OVERLAODS								*/
std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << std::endl;
	os << "AForm: " << f.getName() << std::endl;
	os << "Signed: " << f.getSignStatus() << std::endl;
	os << "Required Sign Grade: " << f.getReqSignGrade() << std::endl;
	os << "Required Execution Grade: " << f.getReqExecGrade() << std::endl;
	os << std::endl;
	return (os);
}
