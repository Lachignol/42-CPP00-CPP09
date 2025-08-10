/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:52:41 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/13 18:53:49 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Contact.hpp"

Contact::Contact(
	const std::string& firstname,
	const std::string& lastname,
	const std::string& nickname,
	const std::string& darkestsecret,
	const std::string& phonenumber)
	: 
	FirstName(firstname),
	LastName(lastname),
	NickName(nickname),
	DarkestSecret(darkestsecret),
	PhoneNumber(phonenumber),
	Active(1)
{
}


void	Contact::PrintContact()
{

	std::cout << "FIRSTNAME:"<< GetFirstname() << '\n';
	std::cout << "LASTNAME:" << GetLastname() << '\n';
	std::cout << "NICKNAME:" << GetNickname()<< '\n';
	std::cout << "PHONE:" << GetPhonenumber() << '\n';
	std::cout << "SECRET:" << GetDarkestsecret() << std::endl;
}

int	Contact::Isactive()
{
	return (Active);
}

std::string	Contact::GetFirstname()
{
	return (FirstName);
}

std::string	Contact::GetLastname()
{
	return (LastName);
}

std::string	Contact::GetNickname()
{
	return (NickName);
}

std::string	Contact::GetDarkestsecret()
{
	return (DarkestSecret);
}

std::string	Contact::GetPhonenumber()
{
	return (PhoneNumber);
}
