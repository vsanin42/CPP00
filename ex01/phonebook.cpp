/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:33:39 by vsanin            #+#    #+#             */
/*   Updated: 2025/03/20 14:38:21 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

class Contact
{
	public:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		Contact(void)
		{
			
		};
	private:
		std::string darkestSecret;
};

void	addContact(void)
{
	Contact newContact;

	std::cout << "Enter first name: ";
	std::cin >> newContact.firstName;
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
