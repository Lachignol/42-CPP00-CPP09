/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:40:43 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/05 17:27:42 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form(void):_gradeToSign(-1),_gradeToExecute(-1)
{
	std::cout << "Constructor by default called" << std::endl;
}

Form::~Form()
{
	std::cout << "Destructor by default called" << std::endl;
}

Form::Form(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute):_name(name),_gradeToSign(gradeToSign),_gradeToExecute(gradeToExecute),_isSigned(0)
{
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &other):_name(other._name),_gradeToSign(other._gradeToSign),_gradeToExecute(other._gradeToExecute),_isSigned(other._isSigned)
{
	std::cout << "Constructor by copie" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_isSigned  = other._isSigned;
	}
	std::cout << "Operator assignement" << std::endl;
		return (*this);
}

const std::string	&Form::getName(void) const
{
	return (this->_name);
}

unsigned int	Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

unsigned int	Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

bool	Form::getisSigned(void)const
{
	return (this->_isSigned);
}


void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	this->_isSigned = 1;
}

std::runtime_error Form::GradeTooHighException(void)
{
	return (std::runtime_error("Grade is Too High"));
}

std::runtime_error Form::GradeTooLowException(void)
{
	return (std::runtime_error("Grade is Too Low"));
}


std::ostream	&operator<<(std::ostream &output, const Form &form)
{
	output << form.getName() << ", Form grade to sign " << form.getGradeToSign() 
	<< ", Form grade to execute " << form.getGradeToExecute() 
	<< ", Form is signed " << (form.getisSigned() == 1 ? "true" : "false");
		return (output);
}
