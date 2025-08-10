/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:01:07 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/15 19:41:57 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie* Zombie::newZombie( std::string name )
{
	Zombie	*nZombie = NULL;

	nZombie = new Zombie(name);
	return (nZombie);
}
