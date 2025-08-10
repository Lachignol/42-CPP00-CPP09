/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:45:35 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/03 15:20:18 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/ICharacter.hpp"

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria()
{
	std::cout << "AMateria constructor default called" << std::endl;
}


AMateria::AMateria(std::string const & type):_type(type)
{	
	std::cout << "AMateria constructor with type arg called" << std::endl;
}

AMateria::AMateria( const AMateria & other):_type(other._type)
{
	std::cout << "AMateria constructor by copy called" << std::endl;
}


AMateria &AMateria::operator=( const AMateria & other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "AMateria assignement operator called" << std::endl;
	return (*this);
}



std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria fonction use called" << target.getName() <<  std::endl;
}
