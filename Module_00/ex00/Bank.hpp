#ifndef __BANK_HPP__
#define __BANK_HPP__

#include <map>
#include "Account.hpp"

class Bank
{
private:
    int _liquidity;
    std::map<int, Account *> _clientAccounts;
    unsigned int accountIdIndex;

    Bank(Bank const &other);
    Bank &operator=(Bank const &other);
    Account* getClientAccount(unsigned int id) const;

public:
    Bank(int liquidity = 0);
    ~Bank();

    const Account& createAccount(int value = 0);
    void deleteAccount(const Account& account);
    void lend(const Account& account, unsigned int value);
    void deposit(unsigned int id, unsigned int value);
    bool withdraw(unsigned int id, unsigned int value);

    int getLiquidity() const;
    void setLiquidity(int liquidity);


    // Manage Account

    // void receiveLoan(unsigned int id, unsigned int value);
};

std::ostream& operator<< (std::ostream& p_os, const Bank& p_bank);

#endif