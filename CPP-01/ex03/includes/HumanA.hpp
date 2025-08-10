/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:29:10 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/18 02:39:29 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

class HumanA
{

	public:
	HumanA(const std::string& name, const Weapon& weapon);
	void attack()const;

	private:
	const Weapon& _weapon;
	std::string _name;

};
