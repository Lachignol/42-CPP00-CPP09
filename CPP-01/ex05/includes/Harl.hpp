/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:52:15 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/19 21:11:22 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _HARL_HPP
#define _HARL_HPP

#include <iostream>

class Harl
{

	public:
	Harl(void);
	~Harl(void);
	void	complain(std::string level);


	private:
	typedef	void	(Harl::*Harlptrfunc)();
	static const std::string	_nameFunc[4];
	static const Harlptrfunc	_arrayfunc[4];
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
};

#endif
