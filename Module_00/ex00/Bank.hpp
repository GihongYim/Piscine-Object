#ifndef __BANK_HPP__
#define __BANK_HPP__

#include <map>
#include "Account.hpp"

class Bank
{
private:
    int _liquidity;
    std::map<int, Account*> _clientAccounts;
    int _accountIdIndex;

public:
    Bank(int liquidity = 0);
    ~Bank();

    Account& createAccount();
    void deleteAccount(Account& account);

    void deposit(Account& account, int value);
    bool withdraw(Account& account, int value);

    void approveLoan(Account& account, int value);
    void collectLoan(Account& account, int value);

    const int& getLiquidity() const;

    friend std::ostream& operator<< (std::ostream& p_os, const Bank& p_bank);
};


#endif