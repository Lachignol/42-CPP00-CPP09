/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:17:33 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/25 20:00:15 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Functions.hpp"

int	main(void)
{

	Base *generateBase = generate();
	Base &generateBasebyReference = *generateBase;

	std::cout << "Identify par pointeur: " << std::endl;
	identify(generateBase);
	std::cout << "Identify par reference: " << std::endl;
	identify(generateBasebyReference);

	delete generateBase;
}
