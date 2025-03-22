/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:33:39 by vsanin            #+#    #+#             */
/*   Updated: 2025/03/22 20:28:27 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

std::string	trim(std::string str)
{
	std::string whitespaces = " \t\r\n";
	size_t start = str.find_first_not_of(whitespaces);
	size_t end = str.find_last_not_of(whitespaces);
	if (start == std::string::npos || end == std::string::npos)
		return "";
	return str.substr(start, end - start + 1);
}

class 	Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}
		Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
		: firstName(fn), lastName(ln), nickname(nn), phoneNumber(pn), darkestSecret(ds) {}
		std::string getFirstName() const { return firstName; }
		std::string getLastName() const { return lastName; }
		std::string getNickname() const { return nickname; }
		std::string getPhoneNumber() const { return phoneNumber; }
		std::string getDarkestSecret() const { return darkestSecret; }
		static Contact	createContact(void)
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
			/* std::cout << "\n" << "New contact: " << "\n";
			std::cout << newContact.getFirstName() << "\n";
			std::cout << newContact.getLastName() << "\n";
			std::cout << newContact.getNickname() << "\n";
			std::cout << newContact.getPhoneNumber() << "\n";
			std::cout << newContact.getDarkestSecret() << "\n" << "\n"; */
			return newContact;
		}
};

class	PhoneBook
{
	private:
		Contact contacts[8];
		int count;
		std::string formatItem(std::string item)
		{
			if (item.length() > 10)
				item = item.substr(0, 9) + ".";
			return item;
		}
		bool parseIndex(std::string input, int &index)
		{
			try
			{
				index = std::stoi(input);
			}
			catch (std::invalid_argument)
			{
				return false;
			}
			return true;
		}
	public:
		PhoneBook() : count(0) {};
		void addContact(Contact newContact)
		{
			this->contacts[count % 8] = newContact;
			count++;
			std::cout << "Contact added successfully!" << "\n";
		}
		void showContactList(void)
		{
			std::string item;
			for (int i = 0; i < 8; i++)
			{
				if (contacts[i].getFirstName().empty())
				{
					if (i == 0)
						std::cout << "The phonebook is empty!" << "\n";
					break;
				}
				std::cout << std::right << std::setw(10) << i << " | ";
				std::cout << std::right << std::setw(10) << formatItem(contacts[i].getFirstName()) << " | ";
				std::cout << std::right << std::setw(10) << formatItem(contacts[i].getLastName()) << " | ";
				std::cout << std::right << std::setw(10) << formatItem(contacts[i].getNickname()) << "\n";
			}
		}
		void findContact(void)
		{
			std::string input;
			int			index;
			bool		found = false;

			std::cout << "Enter index of the contact to find: ";
			std::getline(std::cin, input);
			while (!parseIndex(input, index))
			{
				std::cout << "Wrong input! Enter a number: ";
				std::getline(std::cin, input);
			}
			for (int i = 0; i < 8; i++)
			{
				if (contacts[i].getFirstName().empty())
					break;
				if (i == index)
				{
					found = true;
					std::cout << "First name: " << "\t" << contacts[i].getFirstName() << "\n";
					std::cout << "Last name: " << "\t" << contacts[i].getLastName() << "\n";
					std::cout << "Nickname: " << "\t" << contacts[i].getNickname() << "\n";
					std::cout << "Phone number: " << "\t" << contacts[i].getPhoneNumber() << "\n";
					std::cout << "Darkest secret: " << "\t" << contacts[i].getDarkestSecret() << "\n";
					break ;
				}
			}
			if (found == false)
				std::cout << "Invalid index!" << "\n";
		}
};

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
			Contact newContact = Contact::createContact();
			phoneBook.addContact(newContact);
		}
		else if (cmd.compare("SEARCH") == 0)
		{
			phoneBook.showContactList();
			phoneBook.findContact();
		}
		else
			continue;
	}
	std::cout << "Bye!" << "\n";
	return 0;
}
