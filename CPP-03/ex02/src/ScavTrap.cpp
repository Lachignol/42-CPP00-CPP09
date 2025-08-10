/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 01:27:59 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/28 01:24:24 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"


ScavTrap::ScavTrap(void):ClapTrap("Default"){}

ScavTrap::ScavTrap(const ScavTrap &other):ClapTrap(other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << "ScavTrap copy constructor called for " << this->_name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
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
	std::cout << "ScavTrap assignment operator called for " << this->_name << std::endl;
}

ScavTrap::ScavTrap(const std::string &name):ClapTrap(name)
{
	std::cout << "ScavTrap :" << this->getName() << " constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}


ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap :" << this->getName() << " destructor called" << std::endl;

}


void ScavTrap::guardGate(void)
{
	std::cout << this->getName() << " ScavTrap is now in Gate keeper mode." 
	<< std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->getHitPoints() > 0)
	{
		if (this->getEnergyPoints() >=1)
		{
			std::cout << "ScavTrap " <<  this->getName()
			<<  " attacks " << target 
			<< " causing: " << this->getAttackDamage() 
			<< " points of damage!" << std::endl;
			this->decrementEnergyPoints(1);
		}
		else 
			std::cout << this->getName() << " have not enougth points of energy for attack target" << std::endl;
	}
	else	
		std::cout << this->getName() << " have 0 hit point he can't attack the target" << std::endl;
}
