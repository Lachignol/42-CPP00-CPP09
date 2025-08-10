/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:07:06 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/27 01:19:37 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int	main(void)
{
	ClapTrap perso1("Bobby");
	ClapTrap perso2("Jack");

	std::cout << std::endl;
	perso1.setAttackDamage(9);
	perso1.attack("Jack");
	perso2.takeDamage(5);
	std::cout << std::endl;
	perso2.beRepaired(3);
	std::cout << std::endl;
	perso2.attack("Bobby");
	perso1.takeDamage(0);
	std::cout << std::endl;
	perso1.printInfos();
	perso2.printInfos();

	return (0);
}
