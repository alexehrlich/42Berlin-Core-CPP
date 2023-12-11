/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:17:25 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/11 11:16:36 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

# define PRINT_MSGS

class Bureaucrat;

class AForm
{

	public:
		AForm(std::string name, std::string target, int sign_grad_req, int exec_grade_req);
		AForm(const AForm& f);
		virtual	~AForm();
		
		std::string	getName() const;
		bool		getSignStatus() const;
		int			getReqSignGrade() const;
		int			getReqExecGrade() const;
		std::string	getTarget() const;

		void			beSigned(const Bureaucrat& b);
		virtual void	execute(const Bureaucrat& executor) const = 0;

	protected:
		AForm();
		AForm&				operator=(const AForm& f);
		void				_execute(const Bureaucrat& executor) const;
		const std::string	_target;
		const std::string	_name;
		bool				_isSigned;
		const int			_sign_grade_req;
		const int			_exec_grade_req;
		
		class AlreadySignedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NotSignedException: public std::exception
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
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif