// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United                      //
//                Created on  : Mon Dec 2  11:43:15 2024                      //
//                Last update : Mon Dec 2  13:46:34 2024                      //
//                Made by : Anton                                             //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <iostream>
#include <string>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ){
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_totalAmount += initial_deposit;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void ){
	_totalAmount -= _amount;
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int	Account::getNbAccounts( void ){ return _nbAccounts; }
int	Account::getTotalAmount( void ){ return _totalAmount; }
int	Account::getNbDeposits( void ){ return _totalNbDeposits; }
int	Account::getNbWithdrawals( void ){ return _totalNbWithdrawals; }
void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << "accounts:" << (int)_nbAccounts 
	<< ";total:" << (int)_totalAmount 
	<< ";deposits:" << ( int)_totalNbDeposits 
	<< ";withdrawals:" << (int)_totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;

	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	if (withdrawal <= _amount){
		_amount -= withdrawal;
		_nbWithdrawals++;

		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
	std::cout << ";withdrawal:refused" << std::endl;
	return false;
}

int		Account::checkAmount( void ) const{ return _amount; }
void	Account::displayStatus( void ) const{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ){
	time_t timestamp = time(NULL);
    struct tm *datetime = std::localtime(&timestamp);
    char output[50];
    strftime(output, 50, "[%Y%m%d_%H%M%S] ", datetime);
	//std::cout << "[19920104_091532] ";
    std::cout << output;
}
