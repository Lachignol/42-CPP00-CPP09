/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:25:32 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/02 16:38:11 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H

#define AMATERIA_H

#include <iostream>


class ICharacter;

class AMateria
{
	protected:
		std::string _type;

	public:

	AMateria();
	virtual ~AMateria();
	AMateria(std::string const & type);
	AMateria( const AMateria & other);
	AMateria &operator=( const AMateria & other);

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

};

#endif
