/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 02:35:39 by ascordil          #+#    #+#             */
/*   Updated: 2025/07/07 01:53:14 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"


RPN::~RPN(void){}

RPN::RPN(void){}

RPN::RPN(const RPN &other):_arguments(other._arguments)
{
 
}
RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->_arguments = other._arguments;
	}
	return (*this);

}

int	RPN::evaluate(const std::string& input)
{
	std::istringstream iss(input);
	std::string token;
	while (iss >> token)
	{
		if (token.size() == 1 && isdigit(token[0])) 
			_arguments.push(token[0] - '0');
		else if (isOperator(token)) 
		{
			if (_arguments.size() < 2)
				throw std::runtime_error("Error");
		    int b = _arguments.top(); 
		    _arguments.pop();
		    int a = _arguments.top();
		    _arguments.pop();
		    _arguments.push(doCalcul(token, a, b));
		}
		else 
			throw std::runtime_error("Error");
	}
	if (_arguments.size() != 1)
		throw std::runtime_error("Error");
	return _arguments.top();
}

int	RPN::doCalcul(std::string &operat,int a ,int b)
{
	if (operat == "+") return a + b;
	if (operat == "-") return a - b;
	if (operat == "*") return a * b;
	if (operat == "/") 
	{
		if (b == 0)
			throw std::runtime_error("Error");
		return a / b;
	}
	throw std::runtime_error("Error");
}


bool	RPN::isOperator(const std::string& token)
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}
