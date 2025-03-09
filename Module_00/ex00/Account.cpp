#include "Account.hpp"

Account::Account(): id(-1), money(0), loan(0)
{

}

Account::Account(int id): id(id), money(0), loan(0)
{

}

int Account::getId() const
{
    return this->id;
}

int Account::getId()
{
    return this->id;
}

const int& Account::getMoney() const
{
    return this->money;
}
const int& Account::getLoan() const 
{
    return this->loan;
}

void Account::deposit(int value)
{
    if (value < 0) {
        std::cout << "deposit value should be positive\n";
        return;
    }
    this->money += value;
}

bool Account::withdraw(int value)
{
    if (this->money - value < 0) {
        std::cout << "withdraw value should be less than deposit money\n";
        return false;
    }
    this->money -= value;
    return true;
}

void Account::takeLoan(int value)
{
    this->loan += value;
}

void Account::repayLoan(int value)
{
    if (this->loan - value < 0) {
        std::cout << "Insufficient loan balance!\n";
    } else {
        this->loan -= value;
    }
}

std::ostream& operator << (std::ostream& p_os, const Account& p_account)
{
    p_os << "[" << p_account.getId() << "] - [" << p_account.getMoney() << "] - [" << p_account.getLoan() << "]";
    return (p_os);
}
