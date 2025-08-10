/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:28:45 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/28 17:28:58 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"
#include "../includes/WrongAnimal.hpp"

WrongCat::WrongCat(void):WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}


WrongCat::WrongCat(const WrongCat& other):WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
		this->type = other.type;
	}
	std::cout << "WrongCat assignement operator called" << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Miaou Miaou" << std::endl;

}


