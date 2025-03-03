#include <iostream>
#include "Bank.hpp"

int main()
{
	{
		Bank bank = Bank(999);
		std::vector<int> accountIDs;

		int accountA;
		accountA = bank.createAccount();
		bank.deposit(accountA, 100);

		int accountB;
		accountB = bank.createAccount();
		bank.deposit(accountB, 100);

		bank.addLiquidity(-200);
		bank.deposit(accountA, 400);

		std::cout << "Account: " << std::endl;
		std::cout << *bank.getClientAccount(accountA) << std::endl;
		std::cout << *bank.getClientAccount(accountB) << std::endl;

		std::cout << " ----- " << std::endl;

		std::cout << "Bank : " << std::endl;
		std::cout << bank << std::endl;

		// 은행돈을 초과해서 대출할때
		bank.lend(accountA, 830);
		// 대출이 가능할때
		bank.lend(accountA, 829);

		std::cout << *bank.getClientAccount(accountA) << std::endl;

		std::cout << bank << std::endl;

		bank.receiveLoan(accountA, 830);

		bank.receiveLoan(accountA, 829);

		std::cout << *bank.getClientAccount(accountA) << std::endl;

		std::cout << bank << std::endl;
	}

	std::cout << "----------------------------------------------" << std::endl;

	{
		Bank bank = Bank(100);

		int accountA = bank.createAccount();

		std::cout << *bank.getClientAccount(accountA) << std::endl;

		bank.deposit(accountA, 100);

		std::cout << *bank.getClientAccount(accountA) << std::endl;

		std::cout << bank << std::endl;
	}

	std::cout << "----------------------------------------------" << std::endl;

	{
		Bank bank = Bank(100);

		int accountA = bank.createAccount();

		const Account* account = bank.getClientAccount(accountA);

		std::cout << bank << '\n';
	}

    return 0;
}
