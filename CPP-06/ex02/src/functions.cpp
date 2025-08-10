/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:51:52 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/24 19:10:15 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include "../includes/Base.hpp"
#include <time.h>
#include <stdint.h>
#include <cstdlib>
#include <iostream>

Base	*generate(void)
{
	std::srand((unsigned int)time(0));
	int	rand = std::rand()%3 ;

	Base	*toReturn;

	switch (rand)
	{
		case 0 :
			std::cout << "Create A" << std::endl;
			toReturn = new A();
			break;
		case 1:
			std::cout << "Create B" << std::endl;
			toReturn = new B();
			break;
		case 2:
			std::cout << "Create C" << std::endl;
			toReturn = new C();
			break;
	}
	return (toReturn);
}



void	identify(Base* p)
{
	A *a = dynamic_cast<A*>(p);
	if (a != NULL)
	{
		std::cout << "this type is A" << std::endl;
		return;
	}
	B *b = dynamic_cast<B*>(p);
	if (b != NULL)
	{
		std::cout << "this type is B" << std::endl;
		return;
	}
	C *c = dynamic_cast<C*>(p);
	if (c != NULL)
	{
		std::cout << "this type is c" << std::endl;
		return;
	}
}

void	identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		static_cast<void>(a);
		std::cout << "this type is A" << std::endl;
		return;
	}
	catch(const std::exception &ex){}
	try
	{
		B &b = dynamic_cast<B&>(p);
		static_cast<void>(b);
		std::cout << "this type is B" << std::endl;
		return;
	}
	catch(const std::exception &ex){}

	try
	{
		C &c = dynamic_cast<C&>(p);
		static_cast<void>(c);
		std::cout << "this type is c" << std::endl;
		return;
	}
	catch(const std::exception &ex){}
}

