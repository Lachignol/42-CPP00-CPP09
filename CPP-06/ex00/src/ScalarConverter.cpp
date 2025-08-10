/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:24:12 by ascordil          #+#    #+#             */
/*   Updated: 2025/06/24 00:26:55 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include <sstream>
#include <string>
#include <climits>
#include <cmath>
#include <cfloat>
#include <limits>


void	ScalarConverter::convert(const std::string &value)
{	
	double doubleValue = 0.0;

	if (isChar(value))
		if (value.length() == 3)
			doubleValue = static_cast<double>(value[1]);
		else
			doubleValue = static_cast<double>(value[0]);

	else if (isInt(value))
	{
		std::istringstream stringStream(value);
		int intValue;
		stringStream >> intValue;
		if (stringStream.fail() || !stringStream.eof()) 
		{
            		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
            		return;
        	}
		doubleValue = static_cast<double>(intValue);
	}
	else if (isDouble(value))
	{
		std::istringstream stringStream(value);
		stringStream >> doubleValue;
		if (stringStream.fail() || !stringStream.eof()) 
		{
            		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
            		return;
        	}
	}
	else if (isFloat(value))
	{
		std::istringstream stringStreamWhithoutF(value.substr(0,value.length()-1));
		float floatValue;
		stringStreamWhithoutF >> floatValue;
		if (stringStreamWhithoutF.fail()|| !stringStreamWhithoutF.eof()) 
		{
            		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
            		return;
        	}
		doubleValue = static_cast<double>(floatValue);
	}
	else if (isPseudoLitteralFF(value))
	{
		if (value == "nanf")
		    doubleValue = std::numeric_limits<double>::quiet_NaN();
		else if (value == "+inff")
		    doubleValue = std::numeric_limits<double>::infinity();
		else if (value == "-inff")
		    doubleValue = -std::numeric_limits<double>::infinity();
	   	}
	else if (isPseudoLitteralF(value))
	{
		if (value == "nan")
		    doubleValue = std::numeric_limits<double>::quiet_NaN();
		else if (value == "+inf")
		    doubleValue = std::numeric_limits<double>::infinity();
		else if (value == "-inf")
		    doubleValue = -std::numeric_limits<double>::infinity();
	   	}
	else
	{
    		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
    		return;
	}
	printChar(doubleValue);
	printInt(doubleValue);
	printFloat(doubleValue);
	printDouble(doubleValue);
}

bool	ScalarConverter::isChar(const std::string &value)
{
	if (value.length() == 1 && (!std::isdigit(value[0])))
		return (true);
	if (value.length() == 3 && value[0] == '\'' && value[2] == '\'')
		return (true);
	return (false);
}

bool	ScalarConverter::isInt(const std::string &value)
{
	size_t	i = 0;

	if (!std::isdigit(value[0]))
	{
		if (value[0] == '-' || value[0] == '+')
			i++;
		else
			return (false);
	}
	while (i < value.length())
	{
		if (!std::isdigit(value[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	ScalarConverter::isFloat(const std::string &value)
{

	size_t	i = 0;
	int	oneDot = 0;
	int	oneF = 0;

	if (!std::isdigit(value[0]))
	{
		if (value[0] == '-' || value[0] == '+')
			i++;
		else
			return (false);
	}
	while (i < value.length())
	{
		if (!(std::isdigit(value[i]) || value[i] == '.' || value[i] == 'f'))
			return (false);
		if (value[i] == '.')
			oneDot++;
		if (value[i] == 'f')
			oneF++;
		i++;
	}
	return (oneDot == 1 && oneF == 1);
}


bool	ScalarConverter::isDouble(const std::string &value)
{

	size_t	i = 0;
	int	oneDot = 0;

	if (!std::isdigit(value[0]))
	{
		if (value[0] == '-' || value[0] == '+')
			i++;
		else
			return (false);
	}
	while (i < value.length())
	{
		if (!(std::isdigit(value[i]) || value[i] == '.'))
			return (false);
		if (value[i] == '.')
			oneDot++;
		i++;
	}
	return (oneDot == 1 );

}

bool	ScalarConverter::isPseudoLitteralFF(const std::string &value)
{
	if (value == "nanf" || value == "-inff" || value == "+inff")
		return (true);
	else 
		return (false);
}

bool	ScalarConverter::isPseudoLitteralF(const std::string &value)
{

	if (value == "nan" || value == "-inf" || value == "+inf")
		return (true);
	else 
		return (false);
}

void	ScalarConverter::printChar(double d)
{
	std::cout << "char: ";
    	if (isNan(d) || d < 0 || d > 127) 
	{
		std::cout << "impossible" << std::endl;
		return;
    	}
    	char c = static_cast<char>(d);
    	if (std::isprint(c))
       	 std::cout << "'" << c << "'" << std::endl;
    	else
        	std::cout << "Non displayable" << std::endl;
}

void	ScalarConverter::printInt(double d)
{
    std::cout << "int: ";
    if (isNan(d) || d < INT_MIN || d > INT_MAX)
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    std::cout << static_cast<int>(d) << std::endl;
}

void ScalarConverter::printFloat(double d)
{
    std::cout << "float: ";
    float f = static_cast<float>(d);
    if (isNan(f))
	std::cout << "nanf" << std::endl;
    else if (isInf(f)) 
    {
        if (f > 0)
            std::cout << "+inff" << std::endl;
        else
            std::cout << "-inff" << std::endl;
    } 
    else 
    {
        std::cout.setf(std::ios::fixed);
        std::cout.precision(1);
        std::cout << f << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double d)
{
    std::cout << "double: ";
    if (isNan(d))
        std::cout << "nan" << std::endl;
    else if (isInf(d)) 
    {
        if (d > 0)
            std::cout << "+inf" << std::endl;
        else
            std::cout << "-inf" << std::endl;
    } 
    else 
    {
        std::cout.setf(std::ios::fixed);
        std::cout.precision(1);
        std::cout << d << std::endl;
    }
}

bool ScalarConverter::isNan(double d)
{
    return d != d;
}

bool ScalarConverter::isInf(double d)
{
    return (d > DBL_MAX) || (d < -DBL_MAX);
}
