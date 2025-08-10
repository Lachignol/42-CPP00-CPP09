/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:27:50 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/28 17:34:24 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H

#define DOG_H

#include <iostream>
#include <cstring>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain *brain;
	public:
		Dog(void);
		~Dog(void);
		Dog(const Dog& other);
		Dog &operator=(const Dog& other);
		void makeSound(void) const;
		Brain *getBrain(void) const;

};


#endif
