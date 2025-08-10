/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:40:43 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/05 17:27:42 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):AForm()
{
	std::cout << "Constructor Presidential pardon form called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor Presidential pardon form called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):AForm("PresidentialPardonForm", 25, 5),_target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):AForm(other)
{
	this->_target = other._target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target  = other._target;
	}
		return (*this);
}

const std::string	&PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}


std::runtime_error PresidentialPardonForm::notSigned(void)const
{
	return (std::runtime_error("The PresidentialPardonForm is not signed"));
}

std::runtime_error PresidentialPardonForm::GradeTooLowForExecute(void)const
{
	return (std::runtime_error("Grade of Bureaucrat is Too Low for execute PresidentialPardonForm"));
}


void	PresidentialPardonForm::execute(const Bureaucrat &executor)const
{
	if (!this->getisSigned())
		throw 	this->notSigned();
		 
	if (executor.getGrade() > this->getGradeToExecute())
		throw	this->GradeTooLowForExecute();
	std::cout << this->getTarget() << "has been pardoned by Zaphod Beeblebrox" << std::endl;
}

