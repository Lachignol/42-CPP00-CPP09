/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:19:38 by ascordil          #+#    #+#             */
/*   Updated: 2025/07/05 02:31:44 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

int main( void ) 
{
	try
	{
		Span sp = Span(22);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		Span sptest = Span(2);
		sptest.addNumber(1);
		sptest.addNumber(1);
		std::cout << sptest.longestSpan() << std::endl;
		sp.showStorage();

		Span sp2 = Span(10);
		sp2.addNumber(1);
		sp2.addNumber(2);
		sp2.addNumber(3);
		sp2.addNumber(4);
		sp2.addNumber(5);
		std::cout << "sp adress and contain:" << &sp << std::endl;
		sp.showStorage();
		std::cout << "sp2 adress and contain: "  << &sp2 << std::endl;
		sp2.showStorage();
		std::cout << "copie de sp a sp2"<< std::endl;
		sp = sp2;
		std::cout << "sp adress and contain" << &sp << std::endl;
		sp.showStorage();
		std::cout << "sp2 adress and contain"  << &sp2 << std::endl;
		sp2.showStorage();
		std::vector<int> v;
		v.push_back(45);
		v.push_back(65);
		v.push_back(78);
		v.push_back(46);
		std::cout << "sp contain after addmultiple number: " << std::endl;
		sp.addMultipleNumber(v.begin(), v.end());
		sp.showStorage();
	 	std::cout << sp.shortestSpan() << std::endl; std::cout << sp.longestSpan() << std::endl;

	}catch(std::exception &exe)
	{
		std::cerr << exe.what() << std::endl;
	}
	return (0) ;
}
