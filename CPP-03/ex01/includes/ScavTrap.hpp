/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:10:14 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/28 01:35:58 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SCAVTRAP_H

#define _SCAVTRAP_H

#include "./ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
	public:
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &other);
		ScavTrap& operator=(const ScavTrap &other);
		~ScavTrap();
		void attack(const std::string& target);
		void guardGate(void);

	private:
		ScavTrap(void);

};
#endif 
