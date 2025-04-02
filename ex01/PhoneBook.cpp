/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:20:29 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/02 14:07:39 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

#include <iomanip>
#include <sstream>
#include <iostream>
#include <string>

std::string PhoneBook::formatItem(const std::string &item)
{
	if (item.length() > 10)
		return item.substr(0, 9) + ".";
	return item;
}

bool PhoneBook::parseIndex(const std::string &input, int &index)
{
	std::istringstream stream(input);
	char c;

	if (!(stream >> index))
		return false;
	if (stream >> c)
		return false;
	return true;
}

PhoneBook::PhoneBook() : count(0) {};

void PhoneBook::addContact(const Contact &newContact)
{
	int index = count % 8;
	contacts[index] = newContact;
	count < 8
	? std::cout << "Contact added successfully!" << "\n"
	: std::cout << "Contact replaced an old one at index [" << index + 1 << "]!" << "\n";
	count++;
}

int PhoneBook::showContactList(void)
{
	for (int i = 0; i < 8; i++)
	{
		if (contacts[i].getFirstName().empty())
		{
			if (i == 0)
			{
				std::cout << "The phonebook is empty!" << "\n";
				return 0;
			}
			break;
		}
		std::cout << std::right << std::setw(10) << i + 1 << " | ";
		std::cout << std::right << std::setw(10) << formatItem(contacts[i].getFirstName()) << " | ";
		std::cout << std::right << std::setw(10) << formatItem(contacts[i].getLastName()) << " | ";
		std::cout << std::right << std::setw(10) << formatItem(contacts[i].getNickname()) << "\n";
	}
	return 1;
}

void PhoneBook::findContact(void)
{
	std::string input;
	int			index;
	bool		found = false;

	std::cout << "Enter the index of the contact to display: ";
	while (!found)
	{
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
			if (i == index - 1)
			{
				found = true;
				std::cout << "First name: " << "\t" << contacts[i].getFirstName() << "\n";
				std::cout << "Last name: " << "\t" << contacts[i].getLastName() << "\n";
				std::cout << "Nickname: " << "\t" << contacts[i].getNickname() << "\n";
				std::cout << "Phone number: " << "\t" << contacts[i].getPhoneNumber() << "\n";
				std::cout << "Darkest secret: " << contacts[i].getDarkestSecret() << "\n";
				break;
			}
		}
		if (!found)
			std::cout << "Invalid index! Select one from the list above: ";
	}	
}
