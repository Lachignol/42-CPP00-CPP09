/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:25:32 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/02 12:09:06 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H

#define CHARACTER_H

#include <iostream>

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private :
		std::string _name;
		AMateria*	inventory[4];
	public:

	Character();
	~Character();
	Character(std::string const & name);
	Character( const Character & other);
	Character &operator=( const Character & other);
	std::string const &getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

};

#endif
