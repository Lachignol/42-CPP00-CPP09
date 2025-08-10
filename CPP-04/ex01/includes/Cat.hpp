/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:27:50 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/28 17:34:24 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_H

#define Cat_H

#include <iostream>
#include <cstring>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain *brain;

	public:
		Cat(void);
		~Cat(void);
		Cat(const Cat& other);
		Cat &operator=(const Cat& other);
		void makeSound(void) const;
		Brain *getBrain(void)const;
};


#endif
