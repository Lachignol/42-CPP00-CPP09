/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 02:35:39 by ascordil          #+#    #+#             */
/*   Updated: 2025/07/09 17:52:33 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"


BitcoinExchange::~BitcoinExchange(void){}

BitcoinExchange::BitcoinExchange(void){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other):_database(other._database)
{
 
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->_database.clear();
		this->_database = other._database;
	}
	return (*this);

}

void	BitcoinExchange::fillDatabase()
{
	std::ifstream File("./assets/data.csv");
	std::string	date;
	std::string	value;
	std::string	header;
	if (!File) 
		std::cerr << "Error with database file" << std::endl;
	std::getline(File,header);
	while (std::getline(File,date,',') && std::getline(File,value))
	{
		date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
		value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
		this->_database[date] = atof(value.c_str());
	}
}

void	BitcoinExchange::show_database()
{
	std::map<std::string,float>::iterator  it = this->_database.begin();
	it++;
	while (it != this->_database.end())
	{
		 
		std::cout << "Date: " << it->first << " Value: "<< it->second << std::endl;
		it++;
	}
}

void	BitcoinExchange::getInput(std::string &inputFile)
{
	std::ifstream input(inputFile.c_str());
	std::string	line;
	std::string	header;

	if (!input)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::getline(input,header);
	while (std::getline(input,line))
	{
		if (line.empty())
			continue;

		std::size_t sep = line.find('|');
		if (sep == std::string::npos)
		{
		    std::cerr << "Error: bad input => " << line << std::endl;
		    continue;
		}

        	std::string date = line.substr(0, sep);
        	std::string value = line.substr(sep + 1);
		date.erase(std::remove(date.begin(), date.end(), ' '),date.end());
		value.erase(std::remove(value.begin(), value.end(), ' '),value.end());
		if(!checkValidValue(value) || !checkDate(date))
			continue;

		std::map<std::string,float>::iterator it = this->_database.upper_bound(date);
		if (it != this->_database.begin())
		{
			--it;
			std::cout << date << " => " << value << " = " << it->second * atof(value.c_str()) << std::endl;
		}
		else
			std::cout << "Error: bad input => " << date << std::endl;
	}


}

bool 	BitcoinExchange::isAllDigits(const std::string& s) 
{
	for (size_t i = 0; i < s.size(); ++i)
        	if (!isdigit(s[i]))
            		return false;
    	return true;
}

bool	BitcoinExchange::checkDate(std::string date)
{

	//check si ya que des digit 
	if (date.length() == 10 && date[4] == '-' && date[7] == '-')
	{
		std::string yearStr = date.substr(0,4);
		std::string monthStr = date.substr(5,2);
		std::string dayStr = date.substr(8,2);
		if (!isAllDigits(yearStr) || !isAllDigits(monthStr) || !isAllDigits(dayStr)) {
		    std::cerr << "Error: bad input => " << date << std::endl;
		    return false;
		}
		std::stringstream year(yearStr), month(monthStr), day(dayStr);
		int intDay, intMonth, intYear;
		day >> intDay;
		month >> intMonth;
		year >> intYear;
		if (checkYear(intYear) &&checkMonth(intMonth) && checkDay(intDay,intMonth,intYear))
			return true;
	}
	std::cerr << "Error: bad input => " << date << std::endl;
	return false;
}


bool	BitcoinExchange::checkValidValue(std::string value)
{
	if (is_castable_to_float(value))
	{

		std::stringstream floatValue(value);
    		float number;
		floatValue >> number;
		if (number < 0.0f)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			return false;
		}

		if (number > 1000.0f)
		{
	    		std::cerr << "Error: too large a number." << std::endl;
			return false;
		}
		return true;
	}
	else
	{
	    std::cerr << "Error: too large a number." << std::endl;
	    return false;
	}
}

bool BitcoinExchange::is_castable_to_float(const std::string& input)
{
	char* end;
	//stock le reste de la conversion si il y en a dans end
	double val = std::strtod(input.c_str(), &end);

	// du coup si end est pas null c'est qu'il y a un reste donc c'est pas bon
	if (*end != '\0')
		return false;

	if (val > std::numeric_limits<float>::max() ||
	    val < -std::numeric_limits<float>::max())
		return false;

	return true;
}

bool BitcoinExchange::checkYear(int year)
{
	if (year >= 2009)
		return true;
	return false;
}

bool BitcoinExchange::checkMonth(int month)
{
	if (month >= 1 && month <= 12)
		return true;
	return false;
}

bool BitcoinExchange::checkDay(int day, int month,int year)
{
	int monthLength[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if (day < 1 )
		return false;
	if (month == 2 && isBisextile(year))
        	return (day <= 29);
	else
        	return (day <= monthLength[month - 1]);
}

bool BitcoinExchange::isBisextile(int year) 
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}


