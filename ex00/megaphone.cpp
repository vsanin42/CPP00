/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:13:40 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/02 13:13:03 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		std::string result;
		for (int i = 1; i < argc; i++)
		{
			std::string arg = argv[i];
			for (size_t j = 0; j < arg.length(); j++)
				arg[j] = std::toupper(arg[j]);
			result += arg;
		}
		std::cout << result << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}
