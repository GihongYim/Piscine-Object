#ifndef __ACCOUNT_HPP__
#define __ACCOUNT_HPP__

#include <iostream>

class Account
{
private:
    size_t id;
    double money;
    int loan;
    static int accountIndex;


    Account();
    Account(int id);
    Account(const Account& account);

    friend class Bank;

public:

    //getter
    size_t getId() const;
    size_t getId();
    double getMoney() const;
    double getMoney();
    // const double& getLoan() const;

    //setter
    // void setValue(int value);

    // void deposit(int value);
    // bool withdraw(int value);

    // void addLoan(int value);
    // void offLoan(int value);

};

std::ostream& operator << (std::ostream& p_os, const Account& p_account);

#endif