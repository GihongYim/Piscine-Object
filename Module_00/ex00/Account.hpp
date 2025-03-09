#ifndef __ACCOUNT_HPP__
#define __ACCOUNT_HPP__

#include <iostream>

class Account
{
private:
    int id;
    int money;
    int loan;

    Account();
    Account(int id);
    Account(const Account& account);

    void deposit(int value);
    bool withdraw(int value);

    void takeLoan(int value);
    void repayLoan(int value);

    friend class Bank;

public:
    int getId() const;
    int getId();
    const int& getMoney() const;
    const int& getLoan() const;

    
    friend std::ostream& operator << (std::ostream& p_os, const Account& p_account);
};

#endif