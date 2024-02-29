#ifndef __BANK_HPP__
# define __BANK_HPP__

#include <iostream>
#include <vector>
#include "Account.hpp"

class Bank
{
private:
	int liquidity;
	std::vector<Account *> clientAccounts;
	int account_index;
public:
	Bank(int liquidity);

	int getLiquidity() const;
	void addLiquidity(int newLiquidity);

	int createAccount();
	void deleteAccount(int id);
	std::vector<Account *> getAllAccounts() const;
	Account getClientAccount(int id) const;

	bool withdraw(int id, int value);
	void deposit(int id, int value);
	void lend(int id, int value);
	void receiveLoan(int id, int value);

};

std::ostream& operator<< (std::ostream& p_os, const Bank& p_bank);
#endif