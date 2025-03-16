#include "Bank.hpp"
#include <iostream>
#include <algorithm>
#include <limits.h>

Bank::Bank(int liquidity): _liquidity(liquidity), _accountIdIndex(0)
{

}

Bank::~Bank()
{
	for (std::map<int, Account*>::iterator it = _clientAccounts.begin(); it != _clientAccounts.end(); it++) {
		delete it->second;
	}
}


Account& Bank::createAccount() {
	if (_accountIdIndex < 0) {
		std::cout << "the number of bank accounts reaches limit\n";
		static Account invalidAccount(-1);
		return invalidAccount;
	}
	Account *account = new Account(_accountIdIndex++);
	_clientAccounts[account->getId()] = account;
	return *account;
}

void Bank::deleteAccount(Account& account) {
	std::map<int, Account*>::iterator it = _clientAccounts.find(account.getId());

	if (it == _clientAccounts.end()){
		std::cout << "Account " <<  account.getId() << " not found" << std::endl;
		return;
	}

	delete it->second;
	_clientAccounts.erase(it);
}

void Bank::approveLoan(Account &account, int value) {
	if (_liquidity < static_cast<int>(value))
	{
		std::cout << "bank have no money\n";
	}
	else if (value > INT_MAX || account.getMoney() + static_cast<int>(value) < 0)
	{
		std::cout << "Account overflow\n";
	}
	else
	{
		account.money = account.getMoney() + value;
		_liquidity -= value;
	}
}

void Bank::deposit(Account &account, int value) {

    if (value < 0) {
		std::cout << "value should be positive" << std::endl;
		return;
	}

	std::map<int, Account*>::iterator iter;

	iter = _clientAccounts.find(account.getId());
	if (iter == _clientAccounts.end()) {
		std::cout << account.getId() << " account not found" << std::endl;
		return;
	}

    int charge = (int)((double)value * 0.05);
	int remain = value - charge;

	this->_liquidity += charge;
	account.deposit(remain);
}

bool Bank::withdraw(Account& account, int value) {

	if (value < 0) {
		std::cout << "value should be positive" << std::endl;
		return false;
	}

	std::map<int, Account*>::iterator iter;
	iter = _clientAccounts.find(account.getId());
	if (iter == _clientAccounts.end())
	{
		std::cout << account.getId() << " account not found" << std::endl;
		return false;
	}
	if (!account.withdraw(value)) {
		return false;
	}

	return true;
}

const int& Bank::getLiquidity() const {
    return this->_liquidity;
}

void Bank::collectLoan(Account& account, int value)
 {
	if (value < 0) {
		std::cout << "value should be positive" << std::endl;
		return;
	}

	std::map<int, Account*>::iterator iter;
	iter = _clientAccounts.find(account.getId());
	if (iter == _clientAccounts.end())
	{
		std::cout << account.getId() << " account not found" << std::endl;
		return;
	}

	iter->second->repayLoan(value);
	this->_liquidity += value;
	return;
}

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank) {
    p_os << "Bank informations : " << std::endl;
    p_os << "Liquidity : " << p_bank.getLiquidity() << std::endl;

	std::map<int, Account*>::const_iterator iter;

    for (iter = p_bank._clientAccounts.begin(); iter != p_bank._clientAccounts.end(); iter++)
	{
        p_os << *iter->second << std::endl;
    }

    return (p_os);
}