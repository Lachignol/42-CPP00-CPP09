/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:07:06 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/28 00:51:05 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"


int main()
{
    std::cout << "=== Test ClapTrap ===" << std::endl;
    ClapTrap ct("Clappy");
    ct.printInfos(); // hitPoints=10, energyPoints=10, attackDamage=0
    ct.attack("target1"); // attaque possible
    ct.takeDamage(5);     // hitPoints passe à 5
    ct.beRepaired(3);     // hitPoints passe à 8, energyPoints à 9
    ct.printInfos();

    std::cout << "\n=== Test ScavTrap ===" << std::endl;
    ScavTrap st("Scavy");
    st.printInfos(); // hitPoints=100, energyPoints=50, attackDamage=20
    st.attack("target2"); // attaque possible
    st.guardGate();       // mode gardien activé
    st.takeDamage(20);    // hitPoints passe à 80
    st.beRepaired(10);    // hitPoints passe à 90, energyPoints à 49
    st.printInfos();

    std::cout << "\n=== Test FragTrap ===" << std::endl;
    FragTrap ft("Fraggy");
    ft.printInfos(); // hitPoints=100, energyPoints=100, attackDamage=30
    ft.attack("target3"); // attaque possible
    ft.highFivesGuys();   // message spécial
    ft.takeDamage(15);    // hitPoints passe à 85
    ft.beRepaired(5);     // hitPoints passe à 90, energyPoints à 99
    ft.printInfos();

    std::cout << "\n=== Test DiamondTrap ===" << std::endl;
    DiamondTrap dt("Diamondy");
    dt.printInfos(); // hitPoints=100 (FragTrap), energyPoints=50 (ScavTrap), attackDamage=30 (FragTrap)
    dt.attack("target4"); // doit utiliser ScavTrap::attack()
    dt.whoAmI();          // affiche Diamondy et Diamondy_clap_name
    dt.takeDamage(30);    // hitPoints passe à 70
    dt.beRepaired(20);    // hitPoints passe à 90, energyPoints à 48
    dt.printInfos();

    std::cout << "\n=== Test cas limites ===" << std::endl;
    // Energy points à 0 : attaque impossible
    for (int i = 0; i < 50; ++i)
        dt.attack("target4"); // consomme énergie jusqu’à 0
    dt.attack("target4"); // message d’erreur énergie insuffisante

    // Hit points à 0 : réparation impossible
    dt.takeDamage(1000); // hitPoints à 0
    dt.beRepaired(10);   // message d’erreur hitPoints à 0

    return 0;
}
