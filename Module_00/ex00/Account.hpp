#ifndef __ACCOUNT_HPP__
#define __ACCOUNT_HPP__

#include <iostream>

class Account
{
private:
    int id;
    int value;
    int loan;

    Account();
public:
    Account(int id);
    
    //getter
    const int& getId() const;
    const int& getValue() const;
    const int& getLoan() const;

    //setter
    void setValue(int value);

    void deposit(int value);
    bool withdraw(int value);

    void addLoan(int value);
    void offLoan(int value);

};

std::ostream& operator << (std::ostream& p_os, const Account& p_account);

#endif