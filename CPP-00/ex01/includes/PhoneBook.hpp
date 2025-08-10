/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:39:00 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/15 12:01:30 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

enum {
    ADD,
    SEARCH,
    EXIT,
    DEFAULT,
};

class PhoneBook
{
	public:
		PhoneBook():numberOfContact(0) {};

	void	AddContact(void);
	void 	Search(void);
	int	checkOnlyDigit(std::string phoneNumber);
	private:
	Contact contacts[8];
	int	numberOfContact; 
	void	PrintAllContacts(void);
	void	IncrementNumberOfContact(int new_index);
	int	GetNumberOfContact(void);
	std::string	SendInputAndVerify(std::string input);
};
#endif
