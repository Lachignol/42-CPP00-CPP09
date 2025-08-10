/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:19:38 by ascordil          #+#    #+#             */
/*   Updated: 2025/07/09 17:40:37 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int main(int count,char ** argv) 
{
	if (count != 2) 
	{
		std::cerr << "Error" << std::endl;
		return 1;
    	}
	RPN rpn;
	try 
	{
		int result = rpn.evaluate(argv[1]);
		std::cout << result << std::endl;
	} catch (std::exception& e) 
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return (0) ;
}
