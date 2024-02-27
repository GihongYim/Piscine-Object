#include <iostream>
#include <vector>

struct Account
{
private:
	const int id;
	int value;

public:
	Account(int id) : id(id), value(0)
	{

	}

	const int getId() {
		return this->id;
	}

	int getValue() {
		return this->value;
	}

	void setValue(int newValue) {
		this->value = newValue;
	}

	void deposit(int value) {
		this->value+= value;
	}

	bool withdraw(int value) {
		if (value > this->value) {
			return false;
		} else {
			this->value -= value;
			return true;
		}
	}

	friend std::ostream& operator << (std::ostream& p_os, const Account& p_account)
	{
		p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
		return (p_os);
	}
};

struct Bank
{
private:
	int liquidity;
	std::vector<Account *> clientAccounts;
	static int account_index;


public:
	Bank() : liquidity(0)
	{
		account_index = 0;
	}

	int getLiquidity() {
		return this->liquidity;
	}

	void setLiquidity(int newLiquidity) {
		this->liquidity = newLiquidity;
	}

	int createAccount() {
		Account newAccount = Account(account_index++);
		this->clientAccounts.push_back(&newAccount);
		return newAccount.getId();
	}

	bool withdraw(int id, int value) {
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

	void deposit(int id, int value) {
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
		account->deposit(value)
	}

	friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
	{
		p_os << "Bank informations : " << std::endl;
		p_os << "Liquidity : " << p_bank.liquidity << std::endl;
		for (auto &clientAccount : p_bank.clientAccounts)
        	p_os << *clientAccount << std::endl;
		return (p_os);
	}
};

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
