/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:46:27 by ascordil          #+#    #+#             */
/*   Updated: 2025/07/02 00:17:45 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

template<typename T>
Array<T>::~Array(void)
{
	delete [] this->tab;
}

template<typename T>
Array<T>::Array(unsigned int sizeOfArray):tab(new T[sizeOfArray]()),_size(sizeOfArray){}


template<typename T>
Array<T>::Array(const Array &other):_size(other._size)
{
	this->tab = new T[other._size];
	for (unsigned int i = 0 ; i < other._size ; i++)
	{
		this->tab[i] = other.tab[i];
	}
}


template<typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		if (this->tab != NULL)
		{
			delete [] this->tab;
		}
		this->tab = new T[other._size];
		for (unsigned int i = 0 ; i < other._size ; i++)
		{
			this->tab[i] = other.tab[i];
		}
		this->_size = other._size;
	}
	return (*this);
}


template<typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)	
		throw std::runtime_error("Index is out of bounds");
	return (this->tab[index]);
}

template<typename T>
unsigned int Array<T>::size()const
{
	return (this->_size);
}
