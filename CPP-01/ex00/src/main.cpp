/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:59:42 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/15 19:08:44 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"


int	main(void)
{
	Zombie zombie1("Zombie-1");
	Zombie *zombieCreate;

	std::cout << "Fonction randomChump ou on a une allocation sur la stack" << std::endl;
	zombie1.randomChump("zombie-2");
	std::cout << "Fonction randomChump apres cette fonction le destructeur est directement appele donc instance non accessible depuis l'exeterieur" << std::endl;
	std::cout << "Fonction newZombie ou on a une allocation sur la heap (malloc ~ new)" << std::endl;
	zombieCreate = zombie1.newZombie("zombie-3");
	std::cout << "Fonction newZombie apres cette fonction le destructeur est pas appele donc instance accessible depuis l'exterieur la preuve j'apelle apres la methode announce" << std::endl;
	zombieCreate->announce();
	std::cout << "J'appel explicitement le destructeur avec delete pour liberer la heap" << std::endl;
	delete zombieCreate;
}

