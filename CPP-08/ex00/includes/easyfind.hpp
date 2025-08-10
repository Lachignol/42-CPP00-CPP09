/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 01:51:36 by ascordil          #+#    #+#             */
/*   Updated: 2025/07/05 01:53:31 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <bits/stdc++.h>

template <typename T>
typename T::iterator	easyfind(T &conteneur, int toFind)
{
	typename T::iterator it = std::find(conteneur.begin(),conteneur.end(),toFind);
	if (it != conteneur.end())
		return (it);
	throw std::runtime_error("Occurence not find");
}

