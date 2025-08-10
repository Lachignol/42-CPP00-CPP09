/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:28:45 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/28 17:28:58 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongDog.hpp"
#include "../includes/WrongAnimal.hpp"

WrongDog::WrongDog(void):WrongAnimal()
{
	this->type = "WrongDog";
	std::cout << "WrongDog constructor called" << std::endl;
}

WrongDog::~WrongDog(void)
{
	std::cout << "WrongDog destructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog &other):WrongAnimal(other)
{
	std::cout << "WrongDog copy constructor called" << std::endl;
}

WrongDog &WrongDog::operator=(const WrongDog &other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
		this->type = other.type;
	}
	std::cout << "WrongDog assignement operator called" << std::endl;
	return (*this);
}

void	WrongDog::makeSound(void) const
{
	std ::cout << "whaouf whaouf" << std::endl;
	
}
