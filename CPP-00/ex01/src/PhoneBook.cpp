/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:55:44 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/15 12:36:50 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include ".././includes/PhoneBook.hpp"
# include <iostream>


void	PhoneBook::AddContact()
{
	std::string	TempFirstName;
	std::string	TempLastName;
	std::string	TempNickName;
	std::string	TempDarkestSecret;
	std::string	TempPhoneNumber;

	while (TempFirstName.empty())
		TempFirstName = SendInputAndVerify("FirstName");

	while (TempLastName.empty())
		TempLastName = SendInputAndVerify("LastName");

	while (TempNickName.empty())
		TempNickName = SendInputAndVerify("NickName");

	while (TempPhoneNumber.empty() || !checkOnlyDigit(TempPhoneNumber))
	{
		if (!checkOnlyDigit(TempPhoneNumber))
			std::cout << "The phone number must be only digit" << std::endl;
		TempPhoneNumber = SendInputAndVerify("PhoneNumber");
	}

	while (TempDarkestSecret.empty())
		TempDarkestSecret = SendInputAndVerify("Darkest secret");

	Contact newContact(
		TempFirstName,
		TempLastName,
		TempNickName,
		TempDarkestSecret,
		TempPhoneNumber);
	contacts[GetNumberOfContact()] = newContact;
	IncrementNumberOfContact(GetNumberOfContact());
}

int	PhoneBook::checkOnlyDigit(std::string phoneNumber)
{
	for (size_t i = 0; i < phoneNumber.length(); i++)
	{
		if (!std::isdigit(phoneNumber[i]))
			return 0;
	}
	return 1;
}

std::string	PhoneBook::SendInputAndVerify(std::string input)
{
	std::string	Temp;

	std::cout << input << ":";  
	if (!std::getline(std::cin, Temp))
		exit(0);
	if (Temp.empty() || std::cin.fail())
	{
		std::cout << input << " must be fill" << std::endl;
		std::cin.clear();
	}
	return (Temp);
}

int	PhoneBook::GetNumberOfContact()
{
	return (numberOfContact);
}

void	PhoneBook::IncrementNumberOfContact(int actualIndex)
{
	if (actualIndex < 7)
	numberOfContact++;
	else
		numberOfContact = 0;
}

void PhoneBook::Search(void)
{
	std::string	index_of_contact;
	std::string cleaningBuffer;

	PrintAllContacts();
	std::cout << "Give the index of contact to show (0 for return to menu): ";  
	if (!std::getline(std::cin, index_of_contact))
			exit(0);
	if (!checkOnlyDigit(index_of_contact) || index_of_contact.empty())
	{
		std::cout << "index must be a number" << std::endl;
		return;
	}
	if (std::atoi(index_of_contact.c_str()) == 0)
		return;
	if ( std::atoi(index_of_contact.c_str()) < 0 ||  
		std::atoi(index_of_contact.c_str()) > 8)
	{
		std::cout << "wrong index" << std::endl;
		return;
	}
	if (!contacts[std::atoi(index_of_contact.c_str()) - 1].Isactive())
	{
		std::cout << "the contact don't exist" << std::endl;
		return;
	}
	contacts[std::atoi(index_of_contact.c_str()) - 1].PrintContact();
	return; 
}

void PhoneBook::PrintAllContacts(void)
{
		int	i;
		size_t	j;
		size_t	SpaceOfColumn;
		std::string Firstname;
		std::string Lastname;
		std::string Nickname;

		i = 0;
		SpaceOfColumn = 10;
		std::cout << "╔══════════╦══════════╦══════════╦══════════╗" << std::endl;
		std::cout << "║id        ║firstname ║lastname  ║nickname  ║" << std::endl;
		std::cout << "╠══════════╬══════════╬══════════╬══════════╣" << std::endl;
		while (contacts[i].Isactive())
		{
			std::cout << "|    ";
			std::cout << i + 1;
			std::cout << "     |";
			j = 0;
			Firstname = contacts[i].GetFirstname();
			while (j < SpaceOfColumn)
			{
				if ((j == SpaceOfColumn - 1) && j < Firstname.length())
				{
					std::cout << ".";
					break;
				}
				if (j < Firstname.length())
					std::cout << Firstname[j];
				else
					std::cout << " ";
				j++;
			}
			std::cout << "|";
			j = 0;
			Lastname = contacts[i].GetLastname();
			while (j < SpaceOfColumn)
			{
				if ((j == SpaceOfColumn - 1) && j < Lastname.length())
				{
					std::cout << ".";
					break;
				}
				if (j < Lastname.length())
					std::cout << Lastname[j];
				else
					std::cout << " ";
				j++;
			}
			std::cout << "|";
			j = 0;
			Nickname = contacts[i].GetNickname();
			while (j < SpaceOfColumn)
			{
				if ((j == SpaceOfColumn - 1) && j < Nickname.length())
				{
					std::cout << ".";
					break;
				}
				if (j < Nickname.length())
					std::cout << Nickname[j];
				else
					std::cout << " ";

				j++;
			}
			std::cout << "|" << std::endl;
			i++;
		}
		std::cout << "╚══════════╩══════════╩══════════╩══════════╝" << std::endl;
}
