/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:07:06 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/28 01:36:52 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int	main(void)
{
	ClapTrap perso1("Bobby");
	ClapTrap perso2("Jack");
	ScavTrap perso3("Brad");

	std::cout << std::endl;
	perso1.setAttackDamage(9);
	perso1.attack("Jack");
	perso3.attack("Jack");
	perso2.takeDamage(5);
	std::cout << std::endl;
	perso2.beRepaired(3);
	std::cout << std::endl;
	perso2.attack("Bobby");
	perso1.takeDamage(0);
	std::cout << std::endl;
	perso1.printInfos();
	perso3.guardGate();
	perso2.printInfos();

	return (0);
}
