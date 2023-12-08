/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:17:25 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/08 10:28:23 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMS_HPP
# define FORMS_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	class AlreadySignedException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	
	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	public:
		Form(std::string name, int sign_grad_req, int exec_grade_req);
		Form(const Form& f);
		~Form();
		
		std::string	getName() const;
		bool		getSignStatus() const;
		int			getReqSignGrade() const;
		int			getReqExecGrade() const;

		void		beSigned(const Bureaucrat& b);

	private:
		Form();
		Form&	operator=(const Form& f);
		const std::string	_name;
		bool				_isSigned;
		const int			_sign_grade_req;
		const int			_exec_grade_req;
		
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif