/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:12:54 by vsanin            #+#    #+#             */
/*   Updated: 2025/03/23 19:24:13 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#include <string>

class	PhoneBook
{
	private:
		Contact 	contacts[8];
		int 		count;
		std::string formatItem(const std::string &item);
		bool 		parseIndex(const std::string &input, int &index);
	public:
		PhoneBook();
		void 		addContact(const Contact &newContact);
		int 		showContactList(void);
		void 		findContact(void);
};

#endif
