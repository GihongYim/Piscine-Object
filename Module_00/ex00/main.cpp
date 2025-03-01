#include <iostream>
#include "Bank.hpp"

int main()
{
	Bank bank = Bank(999);
	
	int accountA;
	accountA = bank.createAccount();
	bank.deposit(accountA, 100);

	int accountB;
	accountB = bank.createAccount();
	bank.deposit(accountB, 100);

	bank.addLiquidity(-200);
	bank.deposit(accountA, 400);


	std::cout << "Account : " << std::endl;
	std::cout << bank.getClientAccount(accountA) << std::endl;
	std::cout << bank.getClientAccount(accountB) << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

	return (0);
}