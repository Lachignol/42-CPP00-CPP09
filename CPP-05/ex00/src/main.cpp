/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:41:14 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/05 17:28:33 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main(void)
{
	try
	{
		/*Bureaucrat *notPossibleToInitialize2 = new Bureaucrat("bobby", 0); // doit renvoyer to high exeception*/
		/*Bureaucrat *notPossibleToInitialize = new Bureaucrat("bobby", 151); // doit renvoyer to low exeception*/
		Bureaucrat *initialiseAtOne = new Bureaucrat("bobby", 1);
		Bureaucrat *initialiseAtOneHundredFifty = new Bureaucrat("Jay", 150);

		initialiseAtOne->incrementGrade(); // doit renvoyer grade too high exception
		initialiseAtOneHundredFifty->decrementGrade(); // doit renvoyer grade too low exception
		
		std::cout << *initialiseAtOneHundredFifty << std::endl;
		std::cout << *initialiseAtOne << std::endl;
		/*std::cout << *notPossibleToInitialize << std::endl;*/
		/*std::cout << *notPossibleToInitialize2 << std::endl;*/
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
