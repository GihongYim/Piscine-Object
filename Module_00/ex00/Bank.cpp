#include "Bank.hpp"

Bank::Bank(int liquidity) : liquidity(liquidity), account_index(0)
{
	
}

int Bank::getLiquidity() const {
	return this->liquidity;
}

void Bank::addLiquidity(int newLiquidity) {
	if (this->liquidity + newLiquidity < 0) {
		std::cout << "bank has no money" << std::endl;
	}
	this->liquidity += newLiquidity;
}

int Bank::createAccount() {
	Account *newAccount = new Account(account_index++);
	for (size_t i = 0; i < this->clientAccounts.size(); i++) {
		if (this->clientAccounts[i] == NULL) {
			this->clientAccounts[i] = newAccount;
			return newAccount->getId();
		}
	}
	this->clientAccounts.push_back(newAccount);
	return newAccount->getId();
}

void Bank::deleteAccount(int id) {
	for (size_t i = 0; i < this->clientAccounts.size(); i++) {
		if (clientAccounts[i] == NULL) continue;
		if (this->clientAccounts[i]->getId() == id) {
			delete this->clientAccounts[i];
			this->clientAccounts[i] = NULL;
			return;
		}
	}
	std::cout << id << " account not found" << std::endl;
}

std::vector<Account *> Bank::getAllAccounts() const {
	return this->clientAccounts;
}

Account Bank::getClientAccount(int id) const {
	if (static_cast<size_t>(id) >= this->clientAccounts.size()) {
		std::cout << id << " account not found" << std::endl;
		return Account(-1);
	}
	return *(this->clientAccounts[id]);
}

bool Bank::withdraw(int id, int value) {
	Account *account = NULL;

	if (value < 0) {
		std::cout << "value should be positive" << std::endl;
		return false; 
	}
	for (size_t i = 0; i < this->clientAccounts.size(); i++) {
		if (clientAccounts[i] == NULL) continue;
		if (this->clientAccounts[i]->getId() == id) {
			account = clientAccounts[i];
			break;
		}
	}
	if (account == NULL) {
		std::cout << id << " account not found" << std::endl;
		return false;
	}
	if (!account->withdraw(value)) {
		std::cout << "Not Enough money" << std::endl;
		return false;
	}
	return true;
}

void Bank::deposit(int id, int value) {
	Account *account = NULL;
	int charge;

	if (value < 0) {
		std::cout << "value should be positive" << std::endl;
		return; 
	}

	for (size_t i = 0; i < this->clientAccounts.size(); i++) {
		if (clientAccounts[i] == NULL) continue;
		if (clientAccounts[i]->getId() == id) {
			account = clientAccounts[i];
			break;
		}
	}
	if (account == NULL) {
		std::cout << id << " account not found" << std::endl;
		return;
	}
	charge = (int)((double)value * 0.05);
	this->addLiquidity(charge);
	account->deposit(value - charge);
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
			clientAccounts[i]->addloan(value);
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
			clientAccounts[i]->offloan(value);
			this->addLiquidity(value);
			return;
		}
	}
	if (account == NULL) {
		std::cout << id << " account not found" << std::endl;
		return;
	}
}

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
{
	std::vector<Account *> clientAccounts = p_bank.getAllAccounts();
	p_os << "Bank informations : " << std::endl;
	p_os << "Liquidity : " << p_bank.getLiquidity() << std::endl;
	for (size_t i = 0; i < clientAccounts.size(); i++) {
		p_os << *clientAccounts[i] << std::endl;
	}
	return (p_os);
}
