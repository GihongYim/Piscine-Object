#include "bank.hpp"

Bank::Bank() : liquidity(0)
{
	account_index = 0;
}

int Bank::getLiquidity() {
	return this->liquidity;
}

void Bank::setLiquidity(int newLiquidity) {
	this->liquidity = newLiquidity;
}

int Bank::createAccount() {
	Account newAccount = Account(account_index++);
	this->clientAccounts.push_back(&newAccount);
	return newAccount.getId();
}

bool Bank::withdraw(int id, int value) {
	Account *account = NULL;
	for (int i = 0; i < this->clientAccounts.size(); i++) {
		if (clientAccounts[i]->getId() == id) {
			account = clientAccounts[i];
			break;
		}
	}
	if (account == NULL) {
		std::cout << id << " account not found" << std::endl;
		return;
	}
	if (!account->withdraw(value)) {
		std::cout << "Not Enough money" << std::endl;
	}
}

void Bank::deposit(int id, int value) {
	Account *account = NULL;
	for (int i = 0; i < this->clientAccounts.size(); i++) {
		if (clientAccounts[i]->getId() == id) {
			account = clientAccounts[i];
			break;
		}
	}
	if (account == NULL) {
		std::cout << id << " account not found" << std::endl;
		return;
	}
	account->deposit(value);
}

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
{
	p_os << "Bank informations : " << std::endl;
	p_os << "Liquidity : " << p_bank.liquidity << std::endl;
	for (auto &clientAccount : p_bank.clientAccounts)
		p_os << *clientAccount << std::endl;
	return (p_os);
}
