/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:45:52 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/30 23:46:07 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/ICharacter.hpp"

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice():AMateria("ice")
{
	std::cout << "Ice constructor default called" << std::endl;
}

Ice::Ice(const Ice & other):AMateria(other)
{
	std::cout << "Ice default copy called" << std::endl;

}


Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	std::cout << "Ice assignement operator called" << std::endl;
	return (*this);
}

AMateria* Ice::clone() const
{
	return ( new Ice(*this));
}


void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
