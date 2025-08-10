/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:17:44 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/18 02:41:09 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Weapon
{
	public:
	Weapon();
	Weapon(const std::string& typeOfWeapon);
	
	const std::string& getType()const;
	void setType(const std::string& newValue);
		 

	private:
	std::string _type;

};

