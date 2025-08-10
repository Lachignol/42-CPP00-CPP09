/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:44:32 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/02 15:12:55 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H

#define CURE_H

#include "./AMateria.hpp"

class Cure : public AMateria
{
	private:


	public:
		Cure();
		~Cure();
		Cure(const Cure & other);
		Cure & operator=(const Cure & other);
		AMateria* clone() const;
		void use(ICharacter& target);


};

#endif

