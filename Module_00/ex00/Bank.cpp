#include "Bank.hpp"
#include <iostream>

Bank::Bank(): liquidity(0.0), clientAccounts(std::vector<Account*>())
{

}

Bank::~Bank()
{
	for (size_t i = 0; i < clientAccounts.size(); i++) {
		delete clientAccounts[i];
		clientAccounts[i] = NULL;
	}
}

const double& Bank::getLiquidity() const {
    return this->liquidity;
}

double& Bank::getLiquidity(){
    return this->liquidity;
}

const Account* Bank::getClientAccount(size_t id) const {
	if (static_cast<size_t>(id) >= this->clientAccounts.size()) {
		std::cout << id << " account not found" << std::endl;
		return NULL;
	}
	return this->clientAccounts[id];
}

Account* Bank::getClientAccount(size_t id) {
	if (static_cast<size_t>(id) >= this->clientAccounts.size()) {
		std::cout << id << " account not found" << std::endl;
		return NULL;
	}
	return this->clientAccounts[id];
}

void Bank::createAccount() {
    // index가 INT_MAX를 초과하여 overflow가 발생하였을때
	// 한번 생성된 Account index는 영원하게 유지 (삭제되어도)
    if (accountIdIndex < 0) {
        std::cout << "You have reached the maximum number of accounts." << std::endl;
        return;
    }

	Account* newAccount = new Account(accountIdIndex++);
    this->clientAccounts.push_back(newAccount);
    return;
}

void Bank::deleteAccount(size_t id) {
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

void Bank::deposit(size_t id, double value) {

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
	int remain = value - charge;

	this->liquidity += charge;
	targetAccount->deposit(remain);
}

bool Bank::withdraw(size_t id, double value) {
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


void Bank::lend(size id, double value) {
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

void Bank::receiveLoan(size_t id, double value) {
	Account *account = NULL;
	if (value < 0) {
		std::cout << "value should be positive" << std::endl;
		return;
	}

	for (size_t i = 0; i < this->clientAccounts.size(); i++) {
		if (clientAccounts[i] == NULL) continue;
		if (clientAccounts[i]->getId() == id) {
			clientAccounts[i]->offLoan(value);
			this->liquidity += value;
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