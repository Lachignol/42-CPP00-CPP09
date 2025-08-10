/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:26:13 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/17 19:33:58 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H

#define INTERN_H

#include <iostream>
#include "AForm.hpp"

enum nameForm
{
	ROBOTOMY,
	SHRUBBERY,
	PRESIDENTIAL,
	DEFAULT,
};

class Intern
{
	private:
		typedef AForm	*(Intern::*FormTab)(const std::string &target);
		FormTab		formTab[3];



	public:
		Intern(void);
		~Intern(void);
		Intern &operator=(const Intern &intern);
		Intern(const Intern &other);
		AForm	*makeForm(const std::string &formName, const std::string &target);
		int	hashFunc(const std::string &formName);
		std::runtime_error unknowForm(void);
		AForm	*makeShrubbery(const std::string &target);
		AForm	*makePresidential(const std::string &target);
		AForm	*makeRobotomy(const std::string &target);

};

#endif
