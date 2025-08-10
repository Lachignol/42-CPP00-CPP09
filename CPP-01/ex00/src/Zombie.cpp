/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:00:35 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/15 19:43:15 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Creation d'un zombie" << std::endl;
}

Zombie::Zombie(std::string name):_name(name)
{
	std::cout << "Creation du zombie: "  << _name << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Destruction du zombie: " << _name << std::endl;
}

std::string Zombie::getName(void)
{
	return (_name);
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
