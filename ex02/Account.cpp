/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:40:34 by vsanin            #+#    #+#             */
/*   Updated: 2025/03/24 01:02:39 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int 	Account::_nbAccounts = 0;
int 	Account::_totalAmount = 0;
int 	Account::_totalNbDeposits = 0;
int 	Account::_totalNbWithdrawals = 0;

int		Account::getNbAccounts( void ) { return _nbAccounts; }
int		Account::getTotalAmount( void ) { return _totalAmount; }
int		Account::getNbDeposits( void ) { return _totalNbDeposits; }
int		Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; }

void	Account::_displayTimestamp(void)
{
	time_t 		timestamp = time(NULL);
	struct tm 	datetime = *localtime(&timestamp);
	char		output[18];

	strftime(output, 18, "[%Y%m%d_%H%M%S]", &datetime);
	std::cout << output;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << "\n"; 
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts()
			  << ";total:" << Account::getTotalAmount()
			  << ";deposits:" << Account::getNbDeposits()
			  << ";withdrawals:" << Account::getNbWithdrawals() << "\n"; 
}

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created" << "\n";
	_nbAccounts++;
	_totalAmount += _amount;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed" << "\n";
}

void 	Account::makeDeposit(int deposit)
{
	int p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";p_amount:" << p_amount
			  << ";deposit:" << deposit 
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits << "\n";
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int p_amount = _amount;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";p_amount:" << p_amount
			  << ";withdrawal:";
	if (_amount > withdrawal)
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		std::cout << withdrawal
				  << ";amount:" << _amount
				  << ";nb_withdrawals:" << _nbWithdrawals << "\n";
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		return true;
	}
	else
	{
		std::cout << "refused" << "\n";
		return false;
	}
}
