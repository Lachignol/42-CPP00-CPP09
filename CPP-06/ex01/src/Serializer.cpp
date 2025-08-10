/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 00:35:37 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/24 19:30:37 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Serializer.hpp"


uintptr_t	Serializer::serialize(Data* ptr)
{
	if (!ptr)
		return (0);
	return (reinterpret_cast<uintptr_t>(ptr));
}


Data*		 Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

