#include "Bank.hpp"
#include <iostream>
#include <algorithm>
#include <limits.h>

Bank::Bank(int liquidity): _liquidity(liquidity)
{

}

Bank::~Bank()
{
	for (std::map<int, Account*>::iterator it = _clientAccounts.begin(); it != _clientAccounts.end(); it++) {
		delete it->second;
	}
}


const Account& Bank::createAccount(int value) {
	int commision = (int)((double) value * 0.05);
	Account *account = new Account(value - commision);
	_clientAccounts[account->getId()] = account;
	return *account;
}


void Bank::deleteAccount(const Account& account) {
	std::map<int, Account*>::iterator it = _clientAccounts.find(account.getId());

	if (it == _clientAccounts.end()){
		std::cout << "Account " <<  account.getId() << " not found" << std::endl;
		return;
	}

	delete it->second;
	_clientAccounts.erase(it);
}

void Bank::lend(Account const &account, unsigned int value) {
	Account *pAccount = getClientAccount(account.getId());
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
		pAccount->money= pAccount->getMoney() + value;
		_liquidity -= value;
	}
}

void Bank::deposit(Account const &account, int value) {

    if (value < 0) {
		std::cout << "value should be positive" << std::endl;
		return;
	}

    Account* targetAccount = getClientAccount(account.getId());


    int charge = (int)((double)value * 0.05);
	int remain = value - charge;

	this->_liquidity += charge;
	targetAccount->deposit(remain);
}

double& Bank::getLiquidity() const {
    return this->_liquidity;
}

const Account* Bank::getClientAccount(unsigned int id) const {
	if (static_cast<unsigned int>(id) >= this->_clientAccounts.size()) {
		std::cout << id << " account not found" << std::endl;
		return NULL;
	}
	return this->_clientAccounts[id];
}

Account* Bank::getClientAccount(unsigned int id) {
	if (static_cast<unsigned int>(id) >= this->_clientAccounts.size()) {
		std::cout << id << " account not found" << std::endl;
		return NULL;
	}
	return this->_clientAccounts[id];
}





bool Bank::withdraw(unsigned int id, double value) {
    Account *targetAccount = NULL;

	if (value < 0) {
		std::cout << "value should be positive" << std::endl;
		return false;
	}
	for (unsigned int i = 0; i < this->_clientAccounts.size(); i++) {
		if (_clientAccounts[i] == NULL) continue;
		if (this->_clientAccounts[i]->getId() == id) {
			targetAccount = _clientAccounts[i];
			break;
		}
	}
	if (targetAccount == NULL) {
		std::cout << id << " account not found" << std::endl;
		return false;
	}
	if (!targetAccount->withdraw(value)) {
		std::cout << "Not Enough money" << std::endl;
		return false;
	}
	return true;
}




void Bank::receiveLoan(unsigned int id, double value) {
	Account *account = NULL;
	if (value < 0) {
		std::cout << "value should be positive" << std::endl;
		return;
	}

	for (unsigned int i = 0; i < this->_clientAccounts.size(); i++) {
		if (_clientAccounts[i] == NULL) continue;
		if (_clientAccounts[i]->getId() == id) {
			_clientAccounts[i]->offLoan(value);
			this->_liquidity += value;
			return;
		}
	}
	if (account == NULL) {
		std::cout << id << " account not found" << std::endl;
		return;
	}
}

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank) {
    p_os << "Bank informations : " << std::endl;
    p_os << "Liquidity : " << p_bank.getLiquidity() << std::endl;

    std::vector<Account*> allClientAccounts;

    for (unsigned int i = 0; i < allClientAccounts.size(); i++) {
        p_os << *allClientAccounts[i] << std::endl;
    }

    return (p_os);
}