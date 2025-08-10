/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:10:14 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/27 02:04:15 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DIAMONDTRAP_H

#define _DIAMONDTRAP_H

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap  &operator=(const DiamondTrap &other);
		~DiamondTrap(void);
		void attack(const std::string& target);
		void whoAmI(void);






	private:
		std::string _name;
		DiamondTrap(void);
};
#endif 
