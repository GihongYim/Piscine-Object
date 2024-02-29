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
	static int account_index;
public:
	Bank();

	int getLiquidity();
	void setLiquidity(int newLiquidity);

	int createAccount();

	bool withdraw(int id, int value);

	void deposit(int id, int value);

	friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank);
};

#endif