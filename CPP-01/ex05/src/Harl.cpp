/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:55:17 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/20 19:12:44 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

const Harl::Harlptrfunc	Harl::_arrayfunc[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
const std::string	Harl::_nameFunc[4] = {"DEBUG","INFO","WARNING","ERROR"};

void	Harl::complain(std::string level)
{
	int	i = 0;

	while (i < 4)
	{
		if (level == _nameFunc[i])
			(this->*_arrayfunc[i])();
		i++;
	}

}

void	Harl::debug(void)
{
	std::cout <<
	"DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" 
	<< std::endl;

}

void	Harl::info(void)
{
	std::cout << 
	"INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
	<< std::endl;

}

void	Harl::warning(void)
{
	std::cout <<
	"WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
	<< std::endl;
}

void	Harl::error(void)
{
	std::cout <<
	"ERROR: This is unacceptable! I want to speak to the manager now."
	<< std::endl;
}
