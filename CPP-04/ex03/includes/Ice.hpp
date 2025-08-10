/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:44:38 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/02 16:35:11 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H

#define ICE_H

#include "./AMateria.hpp"

class Ice: public AMateria
{

	private:
		

	public:
		Ice();
		~Ice();
		Ice(const Ice & other);
		Ice &operator=(const Ice &other);
		AMateria* clone() const;
		void use(ICharacter& target);
		

};


#endif
