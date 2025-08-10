/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:19:38 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/23 20:39:24 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int	main(int count,char **argv)
{

	if (count == 2)
	{
		std::string value = argv[1];
		ScalarConverter::convert(value);
	}
	else
		std::cout << "Format: "<< argv[0] << " [value to convert]" << std::endl;





	return (0);
}
