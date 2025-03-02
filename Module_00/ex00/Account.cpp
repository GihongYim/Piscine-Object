#include "Account.hpp"

Account::Account(): id(-1), value(0), loan(0)
{

}

Account::Account(int id): id(id), value(0), loan(0)
{

}

const int& Account::getId() const
{
    return this->id;
}

const int& Account::getValue() const
{
    return this->value;
}

const int& Account::getLoan() const
{
    return this->loan;
}

void Account::setValue(int value)
{
    this->value = value;
}

void Account::deposit(int value)
{
    this->value += value;
}

bool Account::withdraw(int value) {
	if (value > this->value) {
		return false;
	} else {
		this->value -= value;
		return true;
	}
}

void Account::addLoan(int value) {
    this->loan += value;
}

void Account::offLoan(int value){
    if (value > this->loan) {
		std::cout << "loan is less than money that you gave (your loan: " << this->loan << ")" << std::endl;
		return ;
	}
	this->loan -= value;
}

std::ostream& operator << (std::ostream& p_os, const Account& p_account)
{
    p_os << "[" << p_account.getId() << "] - [" << p_account.getValue() << "] - [" << p_account.getLoan() << "]";
    return (p_os);
}
