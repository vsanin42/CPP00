/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:25:17 by vsanin            #+#    #+#             */
/*   Updated: 2025/03/23 19:16:17 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#include <iostream>
#include <string>

static std::string	trim(const std::string &str);

Contact::Contact()
: firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

Contact::Contact(const std::string &fn,
				 const std::string &ln,
				 const std::string &nn,
				 const std::string &pn,
				 const std::string &ds)
: firstName(fn), lastName(ln), nickname(nn), phoneNumber(pn), darkestSecret(ds) {}

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }

Contact	Contact::createContact(void)
{
	std::string info[5];
	std::string prompts[] = {
		"Enter first name: ",
		"Enter last name: ",
		"Enter nickname: ",
		"Enter phone number: ",
		"Enter darkest secret: "
	};
	for (int i = 0; i < 5; i++)
	{
		do {
			std::cout << prompts[i];
			std::getline(std::cin, info[i]);
			info[i] = trim(info[i]);
		} while (info[i].empty()); 
	}
	Contact newContact = Contact(info[0], info[1], info[2], info[3], info[4]);
	return newContact;
}

static std::string	trim(const std::string &str)
{
	std::string whitespaces = " \t\r\n";
	size_t start = str.find_first_not_of(whitespaces);
	size_t end = str.find_last_not_of(whitespaces);
	if (start == std::string::npos || end == std::string::npos)
		return "";
	return str.substr(start, end - start + 1);
}
