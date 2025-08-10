/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 02:34:24 by ascordil          #+#    #+#             */
/*   Updated: 2025/07/09 17:45:55 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <bits/stdc++.h>

class BitcoinExchange
{
	private:
		std::map<std::string,float>	_database;


	public:
		~BitcoinExchange(void);
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		void	fillDatabase();
		void	getInput(std::string &inputFile);
		void	show_database();
		bool	checkValidValue(std::string value);
		bool	checkDate(std::string date);
		bool 	is_castable_to_float(const std::string& input);
		bool 	checkDay(int day, int month ,int year);
		bool 	checkMonth(int month);
		bool 	checkYear(int year);
		bool 	isBisextile(int year);
		bool 	isAllDigits(const std::string& s);
};
