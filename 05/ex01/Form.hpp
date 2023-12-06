/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:17:25 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/06 15:51:34 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMS_HPP
# define FORMS_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form
{
	public:
		Form(std::string name, int sign_grad_req, int exec_grade_req);
		Form(const Form& f);
		~Form();
		
		std::string	getName() const;
		bool		getSignStatus() const;
		int			getReqSignGrade() const;
		int			getReqExecGrade() const;

		void	getSigned(const Bureaucrat& b) throw();

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