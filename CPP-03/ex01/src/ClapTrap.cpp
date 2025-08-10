/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:09:30 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/28 01:28:15 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"


ClapTrap::ClapTrap(){}

ClapTrap::ClapTrap(const std::string &name):_name(name),_hitPoints(10),_energyPoints(10),_attackDamage(0)
{
	std::cout << "Constructor called and create: " << this->getName() 
	<< " with hit points: " << this->getHitPoints()
	<< " energy points: " << this->getEnergyPoints()
	<< " attack damage: " << this->getAttackDamage()
	<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other):_name(other._name),_hitPoints(other._hitPoints),_energyPoints(other._energyPoints),_attackDamage(other._attackDamage)
{
	std::cout << "Constructor by copie called and create:" << this->getName() 
	<< " with hit points: " << this->getHitPoints() 
	<< " energy points: " << this->getEnergyPoints()
	<< " attack damage: " << this->getAttackDamage()
	<< std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);

}


ClapTrap::~ClapTrap()
{

	std::cout << "Destructor called for:" << this->getName()
	<< std::endl;
}

const std::string  &ClapTrap::getName(void)
{
	return (this->_name);
}

const unsigned int &ClapTrap::getHitPoints(void)
{
	return (this->_hitPoints);
}

const unsigned int &ClapTrap::getEnergyPoints(void)
{
	return (this->_energyPoints);
}


const unsigned int &ClapTrap::getAttackDamage(void)
{
	return (this->_attackDamage);
}

void ClapTrap::setAttackDamage(unsigned int attackDamageValue)
{
	this->_attackDamage = attackDamageValue;
}

void ClapTrap::decrementEnergyPoints(const unsigned int &decrementValue)
{

	if (this->getEnergyPoints() >= decrementValue)
		this->_energyPoints -= decrementValue;
	else
		this->_energyPoints = 0;

}


void ClapTrap::decrementHitPoints(const unsigned int &decrementValue)
{

	if (this->getHitPoints() >= decrementValue)
		this->_hitPoints -= decrementValue;
	else
		this->_hitPoints = 0;

}

void ClapTrap::incrementHitPoints(const unsigned int &incrementValue)
{
		this->_hitPoints += incrementValue;
}

void ClapTrap::printInfos(void)
{
	std::cout << this->getName()
	<< "--hit points: "
	<< this->getHitPoints()
	<< "; energy points: "
	<< this->getEnergyPoints()
	<< "; attack damage: "
	<< this->getAttackDamage()
	<< std::endl;

}


void ClapTrap::attack(const std::string& target)
{
	if (this->getHitPoints() > 0)
	{
		if (this->getEnergyPoints() >=1)
		{
			std::cout << "ClapTrap " <<  this->getName()
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


void ClapTrap::takeDamage(unsigned int amount)
{

	if (this->getHitPoints() > 0)
	{
		this->decrementHitPoints(amount);
		std::cout << "ClapTrap " <<  this->getName() 
		<< " take " << amount
		<< " points of damage! and have now: "
		<< this->getHitPoints() << " hit points" << std::endl;
	}
	else 
		std::cout << this->getName() << " have already 0 hit points " << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPoints() > 0)
	{
		if (this->getEnergyPoints() >=1)
		{
			this->incrementHitPoints(amount);
			this->decrementEnergyPoints(1);
			std::cout << "ClapTrap " <<  this->getName()
			<<  " regains: "
			<< amount << " and have now:"<< this->getHitPoints()
			<< " hitPoints" << std::endl;
		}
		else 
			std::cout << this->getName() << " have not enougth points of energy" << std::endl;
	}
	else	
		std::cout << this->getName() << " have 0 hit point he can't be repaired" << std::endl;
}
