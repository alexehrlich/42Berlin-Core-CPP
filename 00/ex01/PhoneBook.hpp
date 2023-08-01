/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 08:16:52 by aehrlich          #+#    #+#             */
/*   Updated: 2023/08/01 08:18:54 by aehrlich         ###   ########.fr       */
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
	Contact*	getContactAtIndex(int index);
	bool		isEmpty()const;

private:
	Contact		_contatcs[8];
	int			_addIndex;
};

#endif 
