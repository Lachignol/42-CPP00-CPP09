/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:41:14 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/17 21:10:19 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 1);        // Grade élevé, peut tout signer/exécuter
        Bureaucrat jim("Jim", 150);      // Grade bas, ne peut rien signer/exécuter

        // Création des formulaires
        ShrubberyCreationForm shrubbery("Home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Fry");

        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        // Tentative de signature par Jim (grade trop bas)
        try
        {
            jim.signForm(shrubbery);
        }
        catch (std::exception &e)
        {
            std::cerr << "Jim cannot sign shrubbery: " << e.what() << std::endl;
        }

        // Signature par Bob (grade suffisant)
        bob.signForm(shrubbery);
        bob.signForm(robotomy);
        bob.signForm(pardon);

        // Tentative d'exécution par Jim (grade trop bas)
        try
        {
            jim.executeForm(shrubbery);
        }
        catch (std::exception &e)
        {
            std::cerr << "Jim cannot execute shrubbery: " << e.what() << std::endl;
        }

        // Exécution par Bob (grade suffisant)
        bob.executeForm(shrubbery);
        bob.executeForm(robotomy);
        bob.executeForm(pardon);

        // Test d'exécution d'un formulaire non signé
        ShrubberyCreationForm unsignedForm("Garden");
        try
        {
            bob.executeForm(unsignedForm);
        }
        catch (std::exception &e)
        {
		//doit etre catch avant par le execute form qui doit recup l'exception//
            std::cerr << "Cannot execute unsigned form: " << e.what() << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}

