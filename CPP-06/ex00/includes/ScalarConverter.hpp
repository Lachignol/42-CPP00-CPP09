/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:20:35 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/24 00:29:46 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONV_H

#define SCALARCONV_H

#include <iostream>

class ScalarConverter
{
	private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter& operator=(const ScalarConverter &other);
	static		bool            isNan(double d);
	static		bool            isInf(double d);
	static		void		printChar(double d);
	static		void		printInt(double d);
	static		void		printFloat(double d);
	static		void		printDouble(double d);
	static		bool	isChar(const std::string &value);
	static		bool	isInt(const std::string &value);
	static		bool	isFloat(const std::string &value);
	static		bool	isDouble(const std::string &value);
	static		bool	isPseudoLitteralFF(const std::string &value);
	static		bool	isPseudoLitteralF(const std::string &value);


	public:
	static	void	convert(const std::string &value);
};

#endif 
