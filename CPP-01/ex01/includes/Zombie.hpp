/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:02:31 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/16 12:56:53 by ascordil         ###   ########.fr       */
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
	Zombie(const std::string);
	~Zombie();
	void		announce(void);
	Zombie* 	zombieHorde( int N,const std::string &name );
	std::string 	getName(void);
	void		setName(const std::string &name);

	private:
	std::string _name;
};

#endif
