/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:27:49 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/17 20:35:34 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

Intern::Intern(void)
{
	formTab[0]= &Intern::makeRobotomy;
	formTab[1]= &Intern::makeShrubbery;
	formTab[2]= &Intern::makePresidential;
	std::cout << "Constructor Intern called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Destructor Intern called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	for (int i = 0 ; i < 3 ; i++)
	{
		formTab[i] = other.formTab[i];
	}
}

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
	{
		for (int i = 0 ; i < 3 ; i++)
		{
			formTab[i] = other.formTab[i];
		}
	}
	return (*this);
}


AForm	*Intern::makeShrubbery(const std::string &target)
{
	std::cout << "Intern creates " << "shrubbery creation form" << std::endl;
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makePresidential(const std::string &target)
{
	std::cout << "Intern creates " << "presidential pardon form" << std::endl;
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeRobotomy(const std::string &target)
{
	std::cout << "Intern creates " << "robotomy request form" << std::endl;
	return (new RobotomyRequestForm(target));
}

int	Intern::hashFunc(const std::string &formName)
{
	if (formName == "robotomy request")
		return (ROBOTOMY);
	else if (formName == "shrubbery creation")
		return (SHRUBBERY);
	else if (formName == "presidential pardon")
		return (PRESIDENTIAL);
	else
		throw unknowForm();
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &target)
{
	return ((this->*formTab[this->hashFunc(formName)])(target));
}


std::runtime_error Intern::unknowForm(void)
{
	return (std::runtime_error("Unknow Form"));
}

