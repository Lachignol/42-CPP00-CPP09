/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:02:31 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/15 19:51:10 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ZOMBIE_HPP

#define _ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie 
{

	public:
	Zombie();
	Zombie(std::string);
	~Zombie();
	void		announce(void);
	void		randomChump( std::string name );
	Zombie*		newZombie( std::string name );
	std::string 	getName(void);

	private:
	std::string _name;
};

#endif
