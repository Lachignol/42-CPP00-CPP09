/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:45:35 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/02 12:27:07 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
	std::cout << "Character destructor called" << std::endl;
}

Character::Character()
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << "Character constructor default called" << std::endl;
}


Character::Character(std::string const & name):_name(name)
{	
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << "Character constructor " << this->getName()<< " with type arg called" << std::endl;
}

Character::Character( const Character & other):_name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i] == NULL)
			this->inventory[i] = NULL;
		else
			this->inventory[i] = other.inventory[i];
	}
	std::cout << "Character constructor by copy called" << std::endl;

}


Character &Character::operator=( const Character & other)
{
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0; i < 4; i++)
			delete this->inventory[i];
		for (int i = 0; i < 4; i++)
		{
			if (other.inventory[i] == NULL)
				this->inventory[i] = NULL;
			else
				this->inventory[i] = other.inventory[i];
		}
	}
	std::cout << "Character assignement operator called" << std::endl;
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->_name);
}


void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "Materia doesn't exist" << std::endl;
		return;
	}
	for (int i = 0 ; i < 4 ; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			return ;
		}
	}
	std::cout << "iventory is full" << std::endl;
}


void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "give index between 0 and 3" << std::endl;
		return ;
	}
	if (this->inventory[idx])
	{
		this->inventory[idx] = NULL;
		return ;
	}
	std::cout << "no Materia found to unequip" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "give index between 0 and 3" << std::endl;
		return ;
	}
	if (!this->inventory[idx])
	{
		std::cout << "no Materia found to use" << std::endl;
		return;
	}
	this->inventory[idx]->use(target);
}

