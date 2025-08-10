/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:28:45 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/30 21:18:20 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"


Animal::Animal(void)
{
	this->type = "Default";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	this->type = other.type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "Animal assignement operator called" << std::endl;
	return (*this);
}


const std::string &Animal::getType(void) const 
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal makeSound" << std::endl;
}
