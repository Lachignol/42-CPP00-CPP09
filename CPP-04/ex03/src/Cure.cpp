/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:45:52 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/03 14:56:51 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"

Cure::~Cure()
{

	std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure():AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure & other):AMateria(other)
{
	std::cout << "Cure default copy called" << std::endl;

}

Cure &Cure::operator=(const Cure & other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	std::cout << "Cure assignement operator called" << std::endl;
	return (*this);
}

AMateria* Cure::clone() const
{
	return ( new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
