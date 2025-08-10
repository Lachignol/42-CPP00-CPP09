/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:07:06 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/27 18:28:43 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int	main(void)
{
	ClapTrap perso1("Bobby");
	ClapTrap perso2("Jack");
	ScavTrap perso3("Brad");
	FragTrap perso4("Rick");


	std::cout << std::endl;
	std::cout << "Print info after constructor called "<< std::endl;
	std::cout << "Claptrap "<< std::endl;
	perso1.printInfos();
	perso2.printInfos();
	std::cout << std::endl;
	std::cout << "ScavTrap "<< std::endl;
	perso3.printInfos();
	std::cout << std::endl;
	std::cout << "FragTrap "<< std::endl;
	perso4.printInfos();
	std::cout << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "Attack " << std::endl;
	perso1.attack("a bastard");
	std::cout << "After set damage to bobby to 9 " << std::endl;
	perso1.setAttackDamage(9);
	perso1.attack("a bastard");
	perso3.attack("another bastard");
	perso4.attack(" a friend to another bastard");
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "Damage " << std::endl;
	perso1.takeDamage(1);
	perso2.takeDamage(5);
	perso3.takeDamage(10);
	perso4.takeDamage(15);
	std::cout << "-------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Repaired " << std::endl;
	perso1.beRepaired(3);
	perso2.beRepaired(10);
	perso3.beRepaired(20);
	perso4.beRepaired(30);
	std::cout << "-------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Special fonction of entity" << std::endl;
	std::cout << std::endl;
	perso3.guardGate();
	perso4.highFivesGuys();
	std::cout << "--------------------------" << std::endl;
	perso4.printInfos();
	perso3.printInfos();
	perso2.printInfos();
	perso1.printInfos();

	return (0);
}
