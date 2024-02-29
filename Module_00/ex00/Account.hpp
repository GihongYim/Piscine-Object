#ifndef __ACCOUNT_HPP__
# define __ACCOUNT_HPP__

#include <iostream>

class Account
{
private:
	const int id;
	int value;

public:
	Account(int id);

	const int getId();

	int getValue();

	void setValue(int newValue);

	void deposit(int value);

	bool withdraw(int value);

	friend std::ostream& operator << (std::ostream& p_os, const Account& p_account);
};


#endif