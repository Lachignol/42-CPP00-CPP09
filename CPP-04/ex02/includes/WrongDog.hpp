/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:27:50 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/28 17:34:24 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_H

#define WRONGDOG_H

#include <iostream>
#include <cstring>
#include "WrongAnimal.hpp"

class WrongDog: public WrongAnimal
{
	public:
		WrongDog(void);
		~WrongDog(void);
		WrongDog(const WrongDog& other);
		WrongDog &operator=(const WrongDog& other);
		void makeSound(void) const;

};


#endif
