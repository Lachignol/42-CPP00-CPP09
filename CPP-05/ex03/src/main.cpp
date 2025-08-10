/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:41:14 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/17 21:07:47 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

int main()
{
    Intern someRandomIntern;

    // Test 1 : Création d'un ShrubberyCreationForm
    try
    {
        AForm* shrubbery = someRandomIntern.makeForm("shrubbery creation", "home");
        std::cout << *shrubbery << std::endl;
        delete shrubbery;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Test 2 : Création d'un RobotomyRequestForm
    try
    {
        AForm* robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *robotomy << std::endl;
        delete robotomy;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Test 3 : Création d'un PresidentialPardonForm
    try
    {
        AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Marvin");
        std::cout << *pardon << std::endl;
        delete pardon;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Test 4 : Formulaire inconnu
    try
    {
        AForm* unknown = someRandomIntern.makeForm("unknown form", "target");
        std::cout << *unknown << std::endl;
        delete unknown;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

