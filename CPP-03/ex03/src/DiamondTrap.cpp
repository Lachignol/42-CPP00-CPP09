/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 01:27:59 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/27 02:05:44 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/ScavTrap.hpp"

DiamondTrap::DiamondTrap(void):ClapTrap("default"),FragTrap("default"),ScavTrap("default"){}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

DiamondTrap::DiamondTrap(const DiamondTrap &other):ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
}

DiamondTrap  &DiamondTrap::operator=(const DiamondTrap &other)
{

	if (this != &other)
	{
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

DiamondTrap::DiamondTrap(const std::string &name):ClapTrap(name + "_clap_name"),FragTrap(name),ScavTrap(name),_name(name)
{	


	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::defaultAttackDamage;
	std::cout << "Diamond : " << this->_name << " constructor called" << std::endl;


}


DiamondTrap::~DiamondTrap()
{
	std::cout << "Diamond : " << this->_name << "destructor called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Diamond name :" << this->_name << " |ClapTrap name:" << ClapTrap::getName() << std::endl;

}

