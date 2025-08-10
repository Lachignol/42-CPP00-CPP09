/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:27:50 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/30 23:14:58 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H

#define ANIMAL_H

#include <iostream>
#include <cstring>

class Animal
{

	protected:
		std::string type;

	public:
		Animal(void);
		virtual ~Animal(void);
		Animal(const Animal &other);
		Animal &operator=(const Animal& other);
		const std::string &getType(void) const;
		virtual void makeSound(void) const = 0;
};


#endif
