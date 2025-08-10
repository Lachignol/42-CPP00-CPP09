/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:52:03 by ascordil          #+#    #+#             */
/*   Updated: 2025/07/05 02:02:25 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::~Span()
{

}

Span::Span(unsigned int maxIntegers):maxStorage(maxIntegers)
{

}

Span::Span(const Span &other):maxStorage(other.maxStorage),storage(other.storage)
{
}

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->maxStorage = other.maxStorage;
		this->storage = other.storage;
	}
	return (*this);
}


void	Span::addNumber(int numberToPush)
{
	if (this->storage.size() >= this->maxStorage)
		throw std::runtime_error("the size of elements stored is at max");
	this->storage.push_back(numberToPush);
}

int	Span::longestSpan()
{
	std::vector<int>::iterator min;
	std::vector<int>::iterator max;
	
	if (this->storage.size() < 2) 
		throw std::runtime_error("No span can be found");
	min = std::min_element(this->storage.begin() , this->storage.end());
	max = std::max_element(this->storage.begin() , this->storage.end());
	return (*max - *min);
}

int	Span::shortestSpan()
{
	int	min = 0;
	std::vector<int>::iterator it;

	if (this->storage.size() < 2)
		throw std::runtime_error("No span can be found");

	std::vector<int> temp = this->storage;
	std::sort(temp.begin(),temp.end());

	min = *(temp.begin()+1) - *temp.begin();
	for (it = temp.begin() + 1 ; it != temp.end()-1 ; it++)
	{
		if (*(it+1) - *it < min)
			min = (*(it+1) - *it);
	}
	return (min);
}


void	Span::showStorage()
{
	std::vector<int>::iterator it = this->storage.begin();

	std::cout << "--------------------------------" << std::endl;
	while( it != this->storage.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "--------------------------------" << std::endl;
}

