/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:27:28 by aehrlich          #+#    #+#             */
/*   Updated: 2023/12/11 14:55:24 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTYREQUESTFORM_HPP
# define ROBOTYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <time.h>

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& f);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& f);
		~RobotomyRequestForm();
		void	execute(const Bureaucrat& executor) const;
	
	private:
		RobotomyRequestForm();
};

#endif
