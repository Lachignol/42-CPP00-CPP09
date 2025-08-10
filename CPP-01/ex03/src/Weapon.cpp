/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:31:32 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/18 02:40:33 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(const std::string& typeOfWeapon):_type(typeOfWeapon){}

const std::string& Weapon::getType()const
{
	return  (_type);
}

void Weapon::setType(const std::string& newValue)
{
	_type = newValue;
}
