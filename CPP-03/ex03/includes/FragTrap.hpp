/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:10:14 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/29 17:04:40 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRAGTRAP_H

#define _FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &other);
		static const unsigned int defaultAttackDamage;
		virtual ~FragTrap(void);
		FragTrap &operator=(const FragTrap &other);
	void highFivesGuys(void);

	private:
		FragTrap(void);
};
#endif 
