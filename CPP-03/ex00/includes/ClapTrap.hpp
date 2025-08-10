/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:10:14 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/28 01:39:03 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CLAPTRAP_H

#define _CLAPTRAP_H

#include<iostream>
#include<cstring>

class ClapTrap
{
	public:
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &other);
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		const std::string  &getName(void);
		const unsigned int &getHitPoints(void);
		const unsigned int &getEnergyPoints(void);
		const unsigned int &getAttackDamage(void);
		void 		    setAttackDamage(unsigned int attackDamageValue);
		void		    decrementEnergyPoints(const unsigned int &decrementValue);
		void 		    decrementHitPoints(const unsigned int &decrementValue);
		void 		    incrementHitPoints(const unsigned int &decrementValue);
		void 		    printInfos(void);






	private:
		std::string _name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
		ClapTrap(void);
};
#endif 
