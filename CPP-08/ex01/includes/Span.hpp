/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 02:52:21 by ascordil          #+#    #+#             */
/*   Updated: 2025/07/05 02:31:45 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>
#include <vector>


class Span
{
	private:
		unsigned int maxStorage;
		std::vector<int>	storage;
		Span(void);


	public:
		~Span();
		Span(unsigned int maxIntegers);
		Span(const Span &other);
		Span &operator=(const Span &other);
		void	addNumber(int numberToPush);
		template<typename T>
		void	addMultipleNumber(T begin, T end);
		void	showStorage();
		int	shortestSpan();
		int	longestSpan();

};

template<typename T>
void	Span::addMultipleNumber(T begin,T end)
{
	if (this->storage.size() + std::distance(begin,end) >= this->maxStorage)
		throw std::runtime_error("the size of elements stored is at max");
	this->storage.insert(storage.end(),begin,end);
	return;
}
