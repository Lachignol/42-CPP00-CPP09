/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:54:49 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/15 12:40:32 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include ".././includes/PhoneBook.hpp"

int hashString(const std::string& str) {
    if (str == "ADD") return ADD;
    if (str == "SEARCH")  return SEARCH;
    if (str == "EXIT")  return EXIT;
    return DEFAULT;
}

int	main(void)
{

	PhoneBook repertoire;
	std::string choice;

	while (1)
	{
		std::cout << "╔════════════════════╗" << std::endl;
		std::cout << "║    PHONEBOOK MENU  ║" << std::endl;
		std::cout << "╚════════════════════╝" << std::endl;
		std::cout << "Options : ADD / SEARCH / EXIT" << std::endl;
		std::cout << "Tapez votre choix : ";

		if (!std::getline(std::cin,choice))
			exit(0);
		switch (hashString(choice))
		{
			case ADD:
				repertoire.AddContact();
            			break;
			case SEARCH:
				repertoire.Search();
            			break;
			case EXIT:
				std::cout << "Hasta la vista" << std::endl;
				exit(0);
            			break;
			default:
				std::cout << "forbidden cmd" << std::endl;
		}
	}
	return (1);
}
