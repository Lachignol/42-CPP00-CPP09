/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:40:43 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/05 17:27:42 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm(void):_gradeToSign(-1),_gradeToExecute(-1)
{
	std::cout << "Constructor by default called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Destructor by default called" << std::endl;
}

AForm::AForm(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute):_name(name),_gradeToSign(gradeToSign),_gradeToExecute(gradeToExecute),_isSigned(0)
{
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &other):_name(other._name),_gradeToSign(other._gradeToSign),_gradeToExecute(other._gradeToExecute),_isSigned(other._isSigned)
{
	std::cout << "Constructor by copie" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_isSigned  = other._isSigned;
	}
	std::cout << "Operator assignement" << std::endl;
		return (*this);
}

const std::string	&AForm::getName(void) const
{
	return (this->_name);
}

unsigned int	AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

unsigned int	AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

bool	AForm::getisSigned(void)const
{
	return (this->_isSigned);
}


void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	this->_isSigned = 1;
}

std::runtime_error AForm::GradeTooHighException(void)
{
	return (std::runtime_error("Grade is Too High"));
}

std::runtime_error AForm::GradeTooLowException(void)
{
	return (std::runtime_error("Grade is Too Low"));
}


std::ostream	&operator<<(std::ostream &output, const AForm &form)
{
	output << form.getName() << ", AForm grade to sign " << form.getGradeToSign() 
	<< ", AForm grade to execute " << form.getGradeToExecute() 
	<< ", AForm is signed " << (form.getisSigned() == 1 ? "true" : "false");
		return (output);
}
