/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:27:50 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/28 17:34:24 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H

#define WRONGCAT_H

#include <iostream>
#include <cstring>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{

	public:
		WrongCat(void);
		~WrongCat(void);
		WrongCat(const WrongCat& other);
		WrongCat &operator=(const WrongCat& other);
		void makeSound(void) const;
};


#endif
