#include <iostream>
#include <vector>

struct Account
{
private:
	const int id;
	int value;

public:
	Account() : id(-1), value(0)
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


public:
	Bank() : liquidity(0)
	{

	}

	int getLiquidity() {
		return this->liquidity;
	}

	void setLiquidity(int newLiquidity) {
		this->liquidity = newLiquidity;
	}

	void addCliendAccount(Account * newAccount) {
		this->clientAccounts.push_back(newAccount);
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
	Account accountA = Account();
	accountA.setId(0);
	accountA.setValue(100);

	Account accountB = Account();
	accountB.setId(1);
	accountB.setValue(100);

	Bank bank = Bank();
	bank.setLiquidity(999);
	bank.addCliendAccount(&accountA);
	bank.addCliendAccount(&accountB);


	// bank.liquidity -= 200;
	// accountA.value += 400;



	std::cout << "Account : " << std::endl;
	std::cout << accountA << std::endl;
	std::cout << accountB << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

	return (0);
}
