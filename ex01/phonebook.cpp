/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:33:39 by vsanin            #+#    #+#             */
/*   Updated: 2025/03/20 21:18:03 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
		{
			firstName = fn;
			lastName = ln;
			nickname = nn;
			phoneNumber = pn;
			darkestSecret = ds;
		}
		std::string getFirstName() const { return firstName; }
		std::string getLastName() const { return lastName; }
		std::string getNickname() const { return nickname; }
		std::string getPhoneNumber() const { return phoneNumber; }
		std::string getDarkestSecret() const { return darkestSecret; }
};

void	addContact(void)
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
			std::cin >> info[i]; // TODO: use getline to get the full line, not jus input until the first whitespace.
        } while (info[i].empty()); 
	}
	Contact newContact = Contact(info[0], info[1], info[2], info[3], info[4]);
	std::cout << newContact.getFirstName() << "\n";
	std::cout << newContact.getLastName() << "\n";
	std::cout << newContact.getNickname() << "\n";
	std::cout << newContact.getPhoneNumber() << "\n";
	std::cout << newContact.getDarkestSecret() << "\n";
}

int main(void)
{
	std::cout << "Welcome to the phonebook! Available commands: ADD, SEARCH, EXIT." << "\n";
	std::string cmd;
	while (1)
	{
		std::cout << "Command: ";
		std::cin >> cmd;
		if (cmd.compare("EXIT") == 0)
			break;
		else if (cmd.compare("ADD") == 0)
		{
			addContact();
		}
		else if (cmd.compare("SEARCH") == 0)
			std::cout << "search :)\n"; // TODO
		else
			continue;
	}
	std::cout << "Bye!" << "\n";
	return 0;
}
