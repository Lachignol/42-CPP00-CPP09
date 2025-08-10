/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:22:32 by ascordil          #+#    #+#             */
/*   Updated: 2025/07/02 00:10:16 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template<typename T>
void	swap(T &v1, T &v2)
{
	T temp = v1;
	v1 = v2;
	v2 = temp;
}

template<typename T>
const T	&min(const T &v1, const T &v2)
{
	return (v2 <= v1 ? v2 : v1);
}

template<typename T>
const T	&max(const T &v1, const T &v2)
{
	return (v2 >= v1 ? v2 : v1);
}
