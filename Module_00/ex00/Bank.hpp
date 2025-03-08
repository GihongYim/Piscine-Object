#ifndef __BANK_HPP__
#define __BANK_HPP__

#include <vector>
#include "Account.hpp"

class Bank
{
private:
    double liquidity;
    std::vector<Account *> clientAccounts;
    size_t accountIdIndex;

public:
    Bank(): liquidity(0.0), clientAccounts(std::vector<Account*>());
    ~Bank();

    // Getter
    const double& getLiquidity() const;
    double& getLiquidity();
    const Account* getClientAccount(size_t id) const;
    Account* getClientAccount(size_t id);

    // Manage Account
    void createAccount();
    void deleteAccount(size_t accountId);

    void deposit(size_t id, double value);
    bool withdraw(size_t id, double value);

    void lend(size_t id, double value);
    void receiveLoan(size_t id, double value);
};

std::ostream& operator<< (std::ostream& p_os, const Bank& p_bank);

#endif