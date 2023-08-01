/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterface.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:35:09 by aehrlich          #+#    #+#             */
/*   Updated: 2023/08/01 16:04:17 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_INTERFACE_H
# define USER_INTERFACE_H

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include "Contact.hpp"
# include "PhoneBook.hpp"

class UserInterface
{
	public:
		UserInterface();
		~UserInterface();

		void	introduction();
		Contact	addRoutine();
		void	searchRoutine(PhoneBook book);

	private:
		std::string	_readField(std::string prompt);
		int			_readIndex();
		std::string	_getTruncatedString(std::string s);
		void		_showSingleEntry(Contact c);
		void		_showAllEntries(PhoneBook book);
};

#endif
