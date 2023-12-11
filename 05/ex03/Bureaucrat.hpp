/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:14:16 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/11 14:46:33 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
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
		Bureaucrat(const Bureaucrat& b);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat&			operator=(const Bureaucrat& b);

		const std::string	getName() const;
		int					getGrade() const;
		void				increaseGrade();
		void				decreaseGrade();
		void				signForm(AForm& f) const;
		void				executeForm(AForm& f) const;
	
	private:
		Bureaucrat();
		const std::string	_name;
		unsigned int		_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif