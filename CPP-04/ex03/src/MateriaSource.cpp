/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:45:35 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/30 23:47:14 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"
#include "../includes/AMateria.hpp"



MateriaSource::~MateriaSource()
{
	for (int i = 0 ; i < 4 ; i ++)
		delete this->memoryMateria[i];
	std::cout << "MateriaSource destructor called" << std::endl;
}


MateriaSource::MateriaSource()
{
	for (int i = 0 ; i < 4 ; i ++)
		this->memoryMateria[i] = NULL;
	std::cout << "MateriaSource constructor default called" << std::endl;
}

MateriaSource::MateriaSource(std::string const & name):_name(name)
{	
	for (int i = 0 ; i < 4 ; i ++)
		this->memoryMateria[i] = NULL;
	std::cout << "MateriaSource constructor with type arg called" << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource & other):_name(other._name)
{
	for (int i = 0 ; i < 4 ; i ++)
	{
		if (!other.memoryMateria[i])
			this->memoryMateria[i] = NULL;
		else	
			this->memoryMateria[i] = other.memoryMateria[i];
	}
	std::cout << "MateriaSource constructor by copy called" << std::endl;
}


MateriaSource &MateriaSource::operator=( const MateriaSource & other)
{
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0 ; i < 4 ; i ++)
			delete this->memoryMateria[i];
		for (int i = 0 ; i < 4 ; i ++)
		{
			if (!other.memoryMateria[i])
				this->memoryMateria[i] = NULL;
			else	
				this->memoryMateria[i] = other.memoryMateria[i];
		}
	}
	std::cout << "MateriaSource assignement operator called" << std::endl;
	return (*this);
}



std::string const & MateriaSource::getName() const
{
	return (this->_name);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	int learn;

	learn = 0;
	if (!materia)
	{
		std::cout << "Is impossible to learn empty materia" << std::endl;
		return;
	}
	for (int i = 0 ; i < 4 ; i++)
	{
		if (!this->memoryMateria[i])
		{
			this->memoryMateria[i] = materia;
			learn = 1;
			break;
		}

	}
	if (!learn)
		std::cout << "Learning box if full !" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0 ; i < 4 ; i++)
	{
		if (this->memoryMateria[i]->getType() == type)
			return (this->memoryMateria[i]->clone());
	}
	std::cout << "No materia of this type was find" << std::endl;
	return (0);
}

