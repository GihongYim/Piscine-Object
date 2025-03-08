#include "Account.hpp"

Account::Account(): id(-1), money(0), loan(0)
{

}

Account::Account(int id): id(id), money(0), loan(0)
{

}

size_t Account::getId() const
{
    return this->id;
}

size_t Account::getId()
{
    return this->id;
}

double Account::getMoney() const
{
    return this->money;
}

double Account::getMoney()
{
    return this->money;
}

std::ostream& operator << (std::ostream& p_os, const Account& p_account)
{
    p_os << "[" << p_account.getId() << "] - [" << p_account.getMoney() << "] - [" << p_account.getLoan() << "]";
    return (p_os);
}
