/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:44:19 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/30 22:57:38 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructor called" << std::endl;
}


Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0 ; i < 100 ; i++)
		this->ideas[i] = other.ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0 ; i < 100 ; i++)
			this->ideas[i] = other.ideas[i];
	}
	std::cout << "Brain assignement operator called" << std::endl;
	return (*this);
}


void	Brain::printIdeas(void)const
{
	for (int i = 0; i < 100 ; i++)
	{
		if (!this->ideas[i].empty())
			std::cout << this->ideas[i] << std::endl;
	}
		
}

void	Brain::setIdea(const std::string &idea , unsigned int idx)
{

	if (idx > 99)
		return;
	this->ideas[idx] = idea;
}


std::string	Brain::getIdea(unsigned int idx)const
{
	if (idx > 99)
		return ("No Value");
	return (this->ideas[idx]);


}
