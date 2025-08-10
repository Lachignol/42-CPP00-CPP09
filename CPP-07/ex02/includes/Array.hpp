/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:30:47 by ascordil          #+#    #+#             */
/*   Updated: 2025/07/03 00:33:25 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template<typename T>
class Array
{
	private:
		T	*tab;
		unsigned int	_size;

	public:

		~Array(void);
		Array(unsigned int sizeOfArray = 0);
		Array(const Array<T> &other);
		Array<T>& operator=(const Array<T> &other);
		T& operator[](unsigned int index);
		unsigned int size()const;
};

#include ".././src/Array.tpp"
