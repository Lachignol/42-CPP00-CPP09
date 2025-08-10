/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:40:43 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/05 17:27:42 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void):AForm()
{
	std::cout << "Constructor Robotomy request form called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor Robotomy request form called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):AForm("RobotomyRequestForm", 72, 45),_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):AForm(other)
{
	this->_target = other._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target  = other._target;
	}
		return (*this);
}

const std::string	&RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}


std::runtime_error RobotomyRequestForm::notSigned(void)const
{
	return (std::runtime_error("The RobotomyRequestForm is not signed"));
}

std::runtime_error RobotomyRequestForm::GradeTooLowForExecute(void)const
{
	return (std::runtime_error("Grade of Bureaucrat is Too Low for execute RobotomyRequestForm"));
}


void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!this->getisSigned())
		throw 	this->notSigned();
		 
	if (executor.getGrade() > this->getGradeToExecute())
		throw	this->GradeTooLowForExecute();
	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
			std::cout << "shhhhlinnngg" << std::endl;
		else if (i % 2 == 0 )
			std::cout << "shlllanggg" << std::endl;
		else
			std::cout << "shlllouuung" << std::endl;
	}
	std::srand(time(0));

	int valeur  = std::rand();
	
	if (valeur % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << "the robotomy failed" << std::endl;
}
