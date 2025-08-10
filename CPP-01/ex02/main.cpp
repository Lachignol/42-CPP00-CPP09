/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:00:20 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/20 16:37:24 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptrstr = &str;
	std::string &refstr = str;

	std::cout << "Adress of string:" << &str <<  std::endl;
	std::cout << "Memory adress of string pointeur:" << &ptrstr <<  std::endl;
	std::cout << "Memory adress of string reference:" << &refstr <<  std::endl;


	std::cout << "Value of string:" << str <<  std::endl;
	std::cout << "Value of string pointeur:" << *ptrstr <<  std::endl;
	std::cout << "Value of string reference:" << refstr <<  std::endl;

}
