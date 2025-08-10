/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:21:17 by ascordil          #+#    #+#             */
/*   Updated: 2025/07/05 02:27:21 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <bits/stdc++.h>

template<typename T>
class MutantStack: public std::stack<T>
{

	public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	~MutantStack(void);
	MutantStack(void);
	MutantStack(const MutantStack &other);
	MutantStack &operator=(const MutantStack &other);
	iterator begin();
	iterator end();
	const_iterator begin()const;
	const_iterator end() const;




};


template<typename T>
MutantStack<T>::~MutantStack(void)
{

}

template<typename T>
MutantStack<T>::MutantStack(void):std::stack<T>()
{

}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other)
{
	if (this != &other)
	{
		std::stack<T>::operator=(other);
	}
	return (*this);
}


template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other):std::stack<T>(other)
{
}


template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}


template<typename T>
typename MutantStack<T>::iterator  MutantStack<T>::end()
{
	//this->c (c'est le conteneur de la std::stack qui est en fait un deque a savoir !!!!!)
	return (this->c.end());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin()const
{
	return (this->c.begin());
}


template<typename T>
typename MutantStack<T>::const_iterator  MutantStack<T>::end()const
{
	return (this->c.end());
}

