/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 01:27:59 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/28 01:59:17 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"


const unsigned int FragTrap::defaultAttackDamage = 30;

FragTrap::FragTrap(void):ClapTrap("default")
{
	std::cout << "FragTrap :default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name):ClapTrap(name)
{

	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap :"<< this->getName() << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other):ClapTrap(other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;

}


FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap :" << this->getName() << " desctructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

void 	FragTrap::highFivesGuys(void)
{
	std::cout << "Special method of Fragtrap : tapes en cinq fait zizir a mon zinc" << std::endl;
}
