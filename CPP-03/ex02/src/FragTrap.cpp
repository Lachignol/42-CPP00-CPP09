/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 01:27:59 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/28 01:27:02 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(void):ClapTrap("default"){}

FragTrap::FragTrap(const std::string &name):ClapTrap(name)
{

	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap :"<< this->getName() << " constructor called" << std::endl;
}


FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap :" << this->getName() << " desctructor called" << std::endl;
}

const	FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

void 	FragTrap::highFivesGuys(void)
{
	std::cout << "Special method of Fragtrap : tapes en cinq fait zizir a mon zinc" << std::endl;
}
