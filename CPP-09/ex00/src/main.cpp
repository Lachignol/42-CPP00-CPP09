/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:19:38 by ascordil          #+#    #+#             */
/*   Updated: 2025/07/09 17:52:47 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int main(int count, char **argv) 
{
	if (count != 2)
	{

		std::cerr << "Usage : ./btc <input file path>" << std::endl;
		return (1);
	}
	else
	{
		BitcoinExchange app;
		std::string input(argv[1]);

		app.fillDatabase();
		app.getInput(input);
		return (0) ;
	}
}
