/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:19:38 by ascordil          #+#    #+#             */
/*   Updated: 2025/07/05 01:53:22 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"

int main( void ) 
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(14);

	try
	{
		std::cout << *easyfind(v,2) << std::endl;
	}catch (std::exception &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	return (0) ;
}
