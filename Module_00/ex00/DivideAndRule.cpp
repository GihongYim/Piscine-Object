#include <iostream>
#include <vector>






int main()
{
	Bank bank = Bank();
	
	int accountA;
	accountA = bank.createAccount();
	bank.deposit(accountA, 100);

	int accountB;
	accountB = bank.createAccount();
	bank.deposit(accountB, 100);





	std::cout << "Account : " << std::endl;
	std::cout << accountA << std::endl;
	std::cout << accountB << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

	return (0);
}
