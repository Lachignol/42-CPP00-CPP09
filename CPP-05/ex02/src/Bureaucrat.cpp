/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:40:43 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/17 18:18:14 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

Bureaucrat::Bureaucrat(void)
{
	std::cout << "Bureaucrat Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name,unsigned int grade):_name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;

}

Bureaucrat::Bureaucrat(const Bureaucrat &other):_name(other._name),_grade(other._grade)
{
	std::cout << "Constructor by copie" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade  = other._grade;
	}
	std::cout << "Operator assignement" << std::endl;
		return (*this);
}

void	Bureaucrat::signForm(AForm &form)const
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &ex) 
	{
		std::cout << *this << " couldn’t sign " << form << " because " << ex.what() << std::endl;

	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &ex) 
	{
		std::cout << "Can't execute " << form.getName() << " for: "  << ex.what() << std::endl;

	}
}

const std::string	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}


void	Bureaucrat::decrementGrade(void)
{
		if (this->getGrade() + 1 > 150)
			throw GradeTooLowException();
		else
			this->_grade++;
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->getGrade() - 1 < 1)
		throw GradeTooHighException();
	else
		this->_grade--;
}

std::runtime_error Bureaucrat::GradeTooHighException(void)
{
	return (std::runtime_error("Grade Too High"));
}

std::runtime_error Bureaucrat::GradeTooLowException(void)
{
	return (std::runtime_error("Grade Too Low"));
}


std::ostream	&operator<<(std::ostream &output, const Bureaucrat &bureaucrat)
{
	output << bureaucrat.getName() << ", Bureaucrat grade " << bureaucrat.getGrade();
		return (output);
}
