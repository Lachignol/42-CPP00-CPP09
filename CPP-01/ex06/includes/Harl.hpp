/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:19:34 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/20 16:10:39 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HARL_HPP
#define _HARL_HPP

#include <iostream>

enum
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	DEFAULT,
};

class Harl
{

	public:
	Harl();
	~Harl();
	void complain( std::string level );
	int	hashInput(std::string input);


	private:
	typedef	void (Harl::*ptrFunc)(void);
	static ptrFunc arrayPtrFunc[4];
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
};

#endif
