/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:31:43 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/08 10:29:09 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*		CONSTRUCTOR - DESTRUCTOR					*/
Form::Form(): _sign_grade_req(1), _exec_grade_req(1){}

Form&	Form::operator=(const Form& f)
{
	if (this != &f) {}
	return (*this);
}

Form::Form(std::string name, int sign_grad_req, int exec_grade_req):
	_name(name), _isSigned(false), _sign_grade_req(sign_grad_req), _exec_grade_req (exec_grade_req)
{}

Form::Form(const Form& f):
	_name(f._name), _isSigned(f._isSigned), _sign_grade_req(f._sign_grade_req), _exec_grade_req (f._exec_grade_req)
{}

Form::~Form(){}

/*		GETTER - SETTER								*/
std::string	Form::getName() const
{
	return (_name);
}

bool	Form::getSignStatus() const
{
	return (_isSigned);
}

int		Form::getReqSignGrade() const
{
	return (_sign_grade_req);
}

int		Form::getReqExecGrade() const
{
	return (_exec_grade_req);
}

/*		CUSTOM EXCEPTIONS							*/
const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade to high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade To Low";
}

const char* Form::AlreadySignedException::what() const throw()
{
	return "Form is already signed";
}

/*		METHODS										*/
void	Form::beSigned(const Bureaucrat& b)
{
	if (this->_isSigned)
		throw Form::AlreadySignedException();
	if (b.getGrade() > this->getReqSignGrade())
		throw Form::GradeTooLowException();
	_isSigned = true;
}

/* OPERATOR OVERLAODS								*/
std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << std::endl;
	os << "Form: " << f.getName() << std::endl;
	os << "Signed: " << f.getSignStatus() << std::endl;
	os << "Required Sign Grade: " << f.getReqSignGrade() << std::endl;
	os << "Required Execution Grade: " << f.getReqExecGrade() << std::endl;
	os << std::endl;
	return (os);
}
