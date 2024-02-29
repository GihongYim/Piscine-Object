#ifndef __ACCOUNT_HPP__
# define __ACCOUNT_HPP__

#include <iostream>

class Account
{
private:
	const int id;
	int value;
	int loan;

public:
	Account(int id);

	int getId() const;

	int getValue() const;

	void setValue(int newValue);

	void deposit(int value);

	bool withdraw(int value);

	void addloan(int value);

	void offloan(int value);

};
std::ostream& operator << (std::ostream& p_os, const Account& p_account);

#endif