/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 08:16:52 by aehrlich          #+#    #+#             */
/*   Updated: 2023/07/31 17:13:55 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook(void);
	~PhoneBook();
	
	void		addContact(Contact c);
	void		searchContact(int index);

private:
	Contact		_contatcs[8];
	int			_addIndex;
};

#endif 
