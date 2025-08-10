/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 02:34:24 by ascordil          #+#    #+#             */
/*   Updated: 2025/07/07 01:56:49 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <bits/stdc++.h>

class RPN
{
	private:
		std::stack<int>	_arguments;


	public:
		~RPN(void);
		RPN(void);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);

		int evaluate(const std::string& input);
		bool isOperator(const std::string& token);
		int	doCalcul(std::string &operat,int a ,int b);
};
