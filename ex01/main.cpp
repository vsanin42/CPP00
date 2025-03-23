/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:33:39 by vsanin            #+#    #+#             */
/*   Updated: 2025/03/23 19:07:01 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

int main(void)
{
	std::string	cmd;
	PhoneBook	phoneBook;
	
	std::cout << "Welcome to the phonebook! "
				 "Available commands: ADD, SEARCH, EXIT." << "\n";
	while (1)
	{
		std::cout << "Command: ";
		std::getline(std::cin, cmd);
		if (cmd.compare("EXIT") == 0)
			break;
		else if (cmd.compare("ADD") == 0)
		{
			Contact newContact = Contact::createContact();
			phoneBook.addContact(newContact);
		}
		else if (cmd.compare("SEARCH") == 0)
		{
			if (phoneBook.showContactList())
				phoneBook.findContact();
		}
		else
			continue;
	}
	std::cout << "Bye!" << "\n";
	return 0;
}
