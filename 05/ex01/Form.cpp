/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:31:43 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/06 15:54:31 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _sign_grade_req(1), _exec_grade_req(1){}
Form&	Form::operator=(const Form& f){}

Form::Form(std::string name, int sign_grad_req, int exec_grade_req):
	_name(name), _isSigned(false), _sign_grade_req(sign_grad_req), _exec_grade_req (exec_grade_req)
{}

Form::Form(const Form& f):
	_name(f._name), _isSigned(f._isSigned), _sign_grade_req(f._sign_grade_req), _exec_grade_req (f._exec_grade_req)
{}

Form::~Form(){}

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

void	Form::getSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _sign_grade_req)
	{
		b.signForm();
	}
	else
		
}
