/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:38:34 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/13 15:23:55 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H
#pragma once

# include <iostream>
# include <string>
# include <cstdlib>

class Contact
{
	public:
		Contact():Active(0){};
		Contact(
			const std::string& firtame,
			const std::string& lastname,
			const std::string&nickname,
			const std::string& darkestsecret,
			const std::string& phonenumber);
	void	PrintContact(void);
	std::string	GetFirstname();
	std::string	GetLastname();
	std::string	GetNickname();
	std::string	GetDarkestsecret();
	std::string	GetPhonenumber();
	int		Isactive();


	private:
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string DarkestSecret;
	std::string PhoneNumber;
	int	Active;
};
#endif
