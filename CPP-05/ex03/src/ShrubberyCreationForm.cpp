/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:40:43 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/05 17:27:42 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void):AForm()
{
	std::cout << "Constructor Shrubbery creation form called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor Shrubbery creation form called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):AForm("ShrubberyCreationForm", 145, 137),_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):AForm(other)
{
	this->_target = other._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target  = other._target;
	}
		return (*this);
}

const std::string	&ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}


std::runtime_error ShrubberyCreationForm::notSigned(void)const
{
	return (std::runtime_error("The ShrubberyCreationForm is not signed"));
}

std::runtime_error ShrubberyCreationForm::GradeTooLowForExecute(void)const
{
	return (std::runtime_error("Grade of Bureaucrat is Too Low for execute ShrubberyCreationForm"));
}

std::runtime_error ShrubberyCreationForm::errorCreationFile(void)const
{
	return (std::runtime_error("Problem during creation and writing file"));
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!this->getisSigned())
		throw 	this->notSigned();
		 
	if (executor.getGrade() > this->getGradeToExecute())
		throw	this->GradeTooLowForExecute();

	std::ofstream MyFile(this->_target.c_str());
	if (!MyFile)
		throw	this->errorCreationFile();
	MyFile << "  /\\  "<< std::endl;
	MyFile << " /  \\ "<< std::endl;
	MyFile << "/    \\"<< std::endl;
	MyFile << "-------"<< std::endl;
	MyFile << "   |   "<< std::endl;
	MyFile << "   |   "<< std::endl;
	MyFile << "The lazy tree from a lazy man"<< std::endl;
	MyFile.close();
}
