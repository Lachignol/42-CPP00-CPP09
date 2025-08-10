/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:23:58 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/18 02:50:00 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

class HumanB
{

	public:
	HumanB();
	HumanB(const std::string& name);
	void	setWeapon(Weapon &weapon);
	void 	attack()const;

	private:
	Weapon *_weapon;
	std::string _name;
};
