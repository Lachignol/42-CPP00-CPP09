/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:53:51 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/16 12:53:18 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
  

Zombie* 	Zombie::zombieHorde( int N, const std::string &name )
{
	Zombie	*zombies;

	zombies = new Zombie[N];
	for (int i = 0 ; i < N; i++)
	{
		zombies[i].setName(name);
	}
	return (zombies);
}
