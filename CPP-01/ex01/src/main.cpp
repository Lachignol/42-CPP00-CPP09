/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:59:42 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/16 12:56:50 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"


int	main(void)
{
	Zombie zombie1("Zombie-1");
	Zombie	*hordeZombie;
	int	i = 0;

	hordeZombie = zombie1.zombieHorde(22,"bobby");
	while (i < 22)
	{
		hordeZombie[i].announce();
		i++;
	}
	delete [] hordeZombie;
}
