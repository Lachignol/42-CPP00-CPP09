/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:41:14 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/06 14:56:29 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat *bobby = new Bureaucrat("bobby", 3);
		/*Bureaucrat *jay = new Bureaucrat("Jay", 3);*/
		Form *formulaire1 = new Form("formulaire 1", 2, 4);
		bobby->signForm(*formulaire1);
		delete bobby;
		delete formulaire1;
	}
	catch(std::exception &ex)
	{
		std::cerr << ex.what() << std::endl;
	}

	return (0);
}
