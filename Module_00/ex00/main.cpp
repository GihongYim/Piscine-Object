#include <iostream>
#include "Bank.hpp"

// void leaks()
// {
// 	system("leaks divide_and_conquer");
// }

int main()
{
	// atexit(leaks);
	{
		Bank bank = Bank(0);

		std::cout << bank << '\n';
		std::cout << "-------" << std::endl;

		Account& accountA = bank.createAccount();
		bank.deposit(accountA, 100);

		Account& accountB = bank.createAccount();
		bank.deposit(accountB, 100);
		bank.deposit(accountA, 400);

		std::cout << "Account: " << std::endl;
		std::cout << accountA << std::endl;
		std::cout << accountB << std::endl;
	
		std::cout << "-------" << std::endl;

		std::cout << "Bank : " << std::endl;
		std::cout << bank << std::endl;

		std::cout << "-------" << std::endl;

		// 은행돈을 초과해서 대출할때
		bank.approveLoan(accountA, 830);

		// 대출이 가능할때
		bank.approveLoan(accountA, 829);

		std::cout << accountA << std::endl;

		std::cout << bank << std::endl;

		bank.collectLoan(accountA, 830);

		bank.collectLoan(accountA, 829);

		std::cout << accountA << std::endl;

		std::cout << bank << std::endl;

		bank.deleteAccount(accountA);

		bank.deposit(accountA, 100);

		// impossible
		// {
			// accountA.deposit(1000);
		
			// std::cout << accountA << std::endl;

			// std::cout << bank << std::endl;
		// }
	}

	std::cout << "----------------------------------------------" << std::endl;

	{
		Bank bank = Bank(100);

		Account& accountA = bank.createAccount();

		std::cout << accountA << '\n';

		bank.deposit(accountA, 100);

		std::cout << accountA << std::endl;

		std::cout << bank << std::endl;
	}

	std::cout << "----------------------------------------------" << std::endl;

	{
		Bank bank = Bank(100);

		Account& accountA = bank.createAccount();

		std::cout << accountA;

		std::cout << bank << '\n';
	}

	std::cout << "----------------------------------------------" << std::endl;

	{
		Bank bank;

		Account& accountA = bank.createAccount();

		std::cout << accountA;

		std::cout << bank << '\n';
	}

	return 0;
}
