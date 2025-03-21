/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:33:39 by vsanin            #+#    #+#             */
/*   Updated: 2025/03/21 18:05:55 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

class 	Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
		: firstName(fn), lastName(ln), nickname(nn), phoneNumber(pn), darkestSecret(ds) {}
		std::string getFirstName() const { return firstName; }
		std::string getLastName() const { return lastName; }
		std::string getNickname() const { return nickname; }
		std::string getPhoneNumber() const { return phoneNumber; }
		std::string getDarkestSecret() const { return darkestSecret; }
};

class	PhoneBook
{
	private:
		//Contact contacts[8];
	public:
		PhoneBook() {std::cout << "ayo\n";};
};

std::string	trim(std::string str)
{
	std::string whitespaces = " \t\r\n";
	size_t start = str.find_first_not_of(whitespaces);
	size_t end = str.find_last_not_of(whitespaces);
	if (start == std::string::npos || end == std::string::npos)
		return "";
	return str.substr(start, end - start + 1);
}

Contact	createContact(void)
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
		std::cout << prompts[i];
		do {
			std::getline(std::cin, info[i]);
			info[i] = trim(info[i]);
        } while (info[i].empty()); 
	}
	Contact newContact = Contact(info[0], info[1], info[2], info[3], info[4]);
	std::cout << "\n" << "New contact: " << "\n";
	std::cout << newContact.getFirstName() << "\n";
	std::cout << newContact.getLastName() << "\n";
	std::cout << newContact.getNickname() << "\n";
	std::cout << newContact.getPhoneNumber() << "\n";
	std::cout << newContact.getDarkestSecret() << "\n" << "\n";
	return newContact;
}

int main(void)
{
	std::cout << "Welcome to the phonebook! "
				 "Available commands: ADD, SEARCH, EXIT." << "\n";
	std::string cmd;
	PhoneBook phoneBook;
	while (1)
	{
		std::cout << "Command: ";
		std::cin >> cmd;
		if (cmd.compare("EXIT") == 0)
			break;
		else if (cmd.compare("ADD") == 0)
		{
			Contact newContact = createContact();
		}
		else if (cmd.compare("SEARCH") == 0)
			std::cout << "search :)\n"; // TODO
		else
			continue;
	}
	std::cout << "Bye!" << "\n";
	return 0;
}
