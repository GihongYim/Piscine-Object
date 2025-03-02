#ifndef __BANK_HPP__
#define __BANK_HPP__

#include <vector>
#include "Account.hpp"

class Bank
{
private:
    int liquidity;
    std::vector<Account *> clientAccounts;
    int accountIdIndex;
    Bank();
public:
    Bank(int liquidity);

    // Getter
    const int& getLiquidity() const;
    const Account* getClientAccount(int id) const;
    const std::vector<Account*>& getAllClientAccounts() const;
    

    // Setter
    void addLiquidity(int value);

    // Manage Account
    int createAccount();
    void modifyAccount(int accountId, int value);
    void deleteAccount(int accountId);

    void deposit(int id, int value);
    bool withdraw(int id, int value);


    void lend(int id, int value);
    void receiveLoan(int id, int value);
};

std::ostream& operator<< (std::ostream& p_os, const Bank& p_bank);

#endif