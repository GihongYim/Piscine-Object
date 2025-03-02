#include "Bank.hpp"
#include <iostream>

Bank::Bank(): liquidity(0), accountIdIndex(0) {

}

Bank::Bank(int liquidity): liquidity(liquidity), accountIdIndex(0) {

}

const int& Bank::getLiquidity() const {
    return this->liquidity;
}

const Account& Bank::getClientAccount(int id) const {
	if (static_cast<size_t>(id) >= this->clientAccounts.size()) {
		std::cout << id << " account not found" << std::endl;
		return NULL;
	}
	return *(this->clientAccounts[id]);
}

const std::vector<Account*>& Bank::getAllClientAccounts() const {
    return this->clientAccounts;
}

void Bank::addLiquidity(int money) {
    if (this->liquidity + money < 0) {
        std::cout << "bank has no money" << std::endl;
    }
    this->liquidity += money;
}

int Bank::createAccount() {
    // index가 INT_MAX를 초과하여 overflow가 발생하였을때
    if (accountIdIndex < 0) {
        std::cout << "You have reached the maximum number of accounts." << std::endl;
        return -1;
    }
    int newAccountId = accountIdIndex;
    accountIdIndex++;

    Account *newAccount = new Account(newAccountId);
    for (unsigned int i = 0; i < this->clientAccounts.size(); i++) {
        if (clientAccounts[i] == NULL) {
            clientAccounts[i] = newAccount;
            return newAccountId;
        }
    }
    this->clientAccounts.push_back(newAccount);
    return newAccountId;
}

void Bank::modifyAccount(int id, int value)
{
    Account * targetAccount = NULL;
    for (unsigned int i = 0; i < clientAccounts.size(); i++) {
        if (clientAccounts[i]->getId() == id) {
            targetAccount = clientAccounts[i];
            break;
        }
    }
    
    if (targetAccount == NULL) {
        std::cout << "Account " <<  id << " not found" << std::endl;
    } else {
        targetAccount->setValue(value);
    }
}

void Bank::deleteAccount(int id) {
    for (unsigned int i = 0; i < clientAccounts.size(); i++) {
        if (clientAccounts[i] == NULL) continue;
        if (clientAccounts[i]->getId() == id) {
            delete clientAccounts[i];
            clientAccounts[i] = NULL;
            return;
        }
    }

    std::cout << "Account " <<  id << " not found" << std::endl;
}



void Bank::deposit(int id, int value) {

    if (value < 0) {
		std::cout << "value should be positive" << std::endl;
		return; 
	}

    Account* targetAccount = NULL;
    for (unsigned int i = 0; i < clientAccounts.size(); i++) {
        if (clientAccounts[i] == NULL) continue;
        if (clientAccounts[i]->getId() == id) {
            targetAccount = clientAccounts[i];
            break;
        }
    }

    if (targetAccount == NULL) {
        std::cout << id << " account not found" << std::endl;
		return;
    }

    int charge = (int)((double)value * 0.05);
	this->addLiquidity(charge);
	targetAccount->deposit(value - charge);
}

bool Bank::withdraw(int id, int value) {
    Account *targetAccount = NULL;

	if (value < 0) {
		std::cout << "value should be positive" << std::endl;
		return false; 
	}
	for (size_t i = 0; i < this->clientAccounts.size(); i++) {
		if (clientAccounts[i] == NULL) continue;
		if (this->clientAccounts[i]->getId() == id) {
			targetAccount = clientAccounts[i];
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


void Bank::lend(int id, int value) {
	Account *account = NULL;

	if (value < 0) {
		std::cout << "value should be positive" << std::endl;
		return; 
	}
	if (value > this->getLiquidity()) {
		std::cout << "lend : bank has not enough money" << std::endl;
		return ;
	}
	
	for (size_t i = 0; i < this->clientAccounts.size(); i++) {
		if (clientAccounts[i] == NULL) continue;
		if (clientAccounts[i]->getId() == id) {
			clientAccounts[i]->addLoan(value);
			this->addLiquidity(-value);
			return;
		}
	}
	if (account == NULL) {
		std::cout << id << " account not found" << std::endl;
		return;
	}
}

void Bank::receiveLoan(int id, int value) {
	Account *account = NULL;
	if (value < 0) {
		std::cout << "value should be positive" << std::endl;
		return; 
	}

	for (size_t i = 0; i < this->clientAccounts.size(); i++) {
		if (clientAccounts[i] == NULL) continue;
		if (clientAccounts[i]->getId() == id) {
			clientAccounts[i]->offLoan(value);
			this->addLiquidity(value);
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

    allClientAccounts = p_bank.getAllClientAccounts();
    for (unsigned int i = 0; i < allClientAccounts.size(); i++) {
        p_os << *allClientAccounts[i] << std::endl;
    }

    return (p_os);
}