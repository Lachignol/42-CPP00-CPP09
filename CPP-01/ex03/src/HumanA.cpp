/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:27:37 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/18 02:42:24 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"
#include "../includes/HumanA.hpp"

HumanA::HumanA(const std::string& name ,const Weapon& weapon): _weapon(weapon),_name(name){}

void HumanA::attack()const
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}


