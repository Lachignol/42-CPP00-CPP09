/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:25:58 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/14 19:25:05 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include "iostream"
#include <ctime>

int	Account::_nbAccounts = 0;
int 	Account::_totalAmount = 0;
int 	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" 
	<< _accountIndex 
	<< ";" 
	<< "amount:"
	<< checkAmount()
	<<";"
	<< "created" << std::endl;
};

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:"
	<< _accountIndex 
	<< ";"
	<< "amount:"
	<< checkAmount() 
	<<";"
	<< "closed" << std::endl;
	
}

void	Account::makeDeposit(int deposit)
{
	int p_amount;

	p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" 
	<< _accountIndex 
	<<";" 
	<< "p_amount:"
	<< p_amount
	<<";"
	<< "deposit:"
	<< deposit 
	<< ";"
	<< "amount:"
	<< checkAmount()
	<< ";"
	<< "nb_deposits:"
	<< _nbDeposits << std::endl;

}

bool Account::makeWithdrawal(int withdrawal)
{
	int p_amount;

	p_amount = _amount;
	if (_amount - withdrawal >= 0)
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_displayTimestamp();
		std::cout<< "index:" 
		<< _accountIndex 
		<< ";" 
		<< "p_amount:"
		<< p_amount 
		<<";"
		<< "withdrawal:"
		<< withdrawal 
		<< ";" << "amount:"
		<< checkAmount()
		<< ";" 
		<< "nb_withdrawals:"
		<< _nbWithdrawals << std::endl;
		return (1);
	}
	else
	{
		_displayTimestamp();
		std::cout << "index:" 
		<< _accountIndex 
		<< ";" 
		<< "p_amount:"
		<< p_amount 
		<<";"
		<< "withdrawal:refused"<< std::endl;
		return (0);
	}

}


int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

 void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() <<  ";" << "total:" << getTotalAmount() << ";" << "deposits:" << getNbDeposits() << ";" << "withdrawals:" << getNbWithdrawals() << std::endl;
}
int	Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:"
	<< _accountIndex 
	<<  ";" 
	<< "amount:" 
	<< checkAmount()
	<< ";" 
	<< "deposits:" 
	<< _nbDeposits 
	<< ";" 
	<< "withdrawals:" 
	<< _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{

	std::time_t actuel = time(0);
   	std::tm *ltm = localtime(&actuel);

	std::cout << "[" << 1900 + ltm->tm_year
	<< (1 + ltm->tm_mon < 10 ? "0" : "") << 1 + ltm->tm_mon
	<< (ltm->tm_mday < 10 ? "0" : "") <<  ltm->tm_mday 
	<< "_"
	<< (0 + ltm->tm_hour < 10 ? "0" : "") 
	<< 0 + ltm->tm_hour 
	<< (1 + ltm->tm_min < 10 ? "0" : "")
	<< 1 + ltm->tm_min 
	<< (1 + ltm->tm_sec < 10 ? "0" : "")
	<< 1 + ltm->tm_sec
	<< "] ";
}
