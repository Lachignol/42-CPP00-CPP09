/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:44:11 by ascordil          #+#    #+#             */
/*   Updated: 2025/07/04 00:35:01 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template<typename Tab,typename size>
void	iter(const Tab* addTab, size sizeTab, void (*Func)(const Tab &tab))
{
	for (size i = 0 ; i < sizeTab ; i++)
	{
		Func(addTab[i]);
	}

}


template<typename Tab, typename size>
void	iter(Tab* addTab, size sizeTab, void (*Func)(Tab &tab))
{

	for (size i = 0 ; i < sizeTab ; i++)
	{
		Func(addTab[i]);
	}
}

template<typename Tab>
void	actionOnTab(Tab &tab)
{
	std::cout << "Dans la fonction non const : " << tab << std::endl;
}

template<typename Tab>
void	actionOnTab(const Tab &tab)
{
	std::cout << "Dans la fonction const : " << tab << std::endl;
}
