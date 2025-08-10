/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:16:59 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/21 20:56:49 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Harl.hpp"

int	main(int count, char **argv)
{
	if (count != 2)
		return (std::cout << "Format : ./harlFilter  <[DEBUG]/[INFO]/[WARNING]/[ERROR]>" << std::endl, 1);
	Harl instance;
	switch (instance.hashInput(std::string(argv[1])))
	{
		case DEBUG:
			std::cout << "[ DEBUG ]" << std::endl;
			instance.complain("DEBUG");
			std::cout << std::endl;
		case INFO:
			std::cout << "[ INFO ]" << std::endl;
			instance.complain("INFO");
			std::cout << std::endl;
		case WARNING:
			std::cout << "[ WARNING ]" << std::endl;
			instance.complain("WARNING");
			std::cout << std::endl;
		case ERROR:
			std::cout << "[ ERROR ]" << std::endl;
			instance.complain("ERROR");
			std::cout << std::endl;
			break;
		default:
			std::cout << "Command not valid" << std::endl;
			break;
	}
	return (0);
}
