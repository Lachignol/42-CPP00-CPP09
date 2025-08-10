/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 00:36:01 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/24 19:18:38 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include	<stdint.h> 

struct Data
{
	std::string name;
	std::string lastName;
	int	age;
};

class Serializer
{
	private:
		Serializer(void);
		~Serializer(void);
		Serializer(const Serializer &other);
		Serializer& operator=(const Serializer &other);
	public:
		static	uintptr_t	serialize(Data* ptr);
		static	Data*		 deserialize(uintptr_t raw);
};
