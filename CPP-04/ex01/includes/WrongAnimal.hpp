/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:27:50 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/30 20:51:34 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H

#define WRONGANIMAL_H

#include <iostream>
#include <cstring>

class WrongAnimal
{

	protected:
		std::string type;
	private:

	public:
		WrongAnimal(void);
		~WrongAnimal(void);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal& other);
		const std::string &getType(void) const;
		void makeSound(void) const;
};


#endif
