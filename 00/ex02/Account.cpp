/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:29:51 by aehrlich          #+#    #+#             */
/*   Updated: 2023/08/01 19:36:50 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout<<"accounts:"<<_nbAccounts<<";total:"<<_totalAmount<<";deposits:"<<_totalNbDeposits<<";withdrawals:"<<_totalNbWithdrawals<<std::endl;
	//print accounts:8;total:12442;deposits:8;withdrawals:6
}

Account::Account()
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";created"<<std::endl;
	//print index:0;amount:42;created
}

Account::Account( int deposit)
{
	_amount = deposit;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";created"<<std::endl;
	//print index:0;amount:42;created
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";closed"<<std::endl;
	//print index:7;amount:8942;closed
}

void	Account::makeDeposit( int deposit )
{
	_totalAmount += deposit;
	_amount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";created"<<std::endl;
	//print index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (withdrawal < _totalAmount)
	{
		_totalAmount -= withdrawal;
		_amount -= withdrawal;
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		//print index:4;p_amount:1321;withdrawal:76;amount:1245;nb_withdrawals:1
		return (true);
	}
	//print [19920104_091532] index:5;p_amount:23;withdrawal:refused
	return (false);
}

int		Account::checkAmount( void )const
{
	return (_amount);
}

void	Account::displayStatus( void )const
{
	_displayTimestamp();
	//print index:7;amount:8942;deposits:1;withdrawals:1
}

void	Account::_displayTimestamp( void )
{
	//print[19920104_091532]
}