#include "Account.hpp"


Account::Account(int id) : id(id), value(0), loan(0)
{

}

int Account::getId() const {
	return this->id;
}

int Account::getValue() const {
	return this->value;
}

void Account::setValue(int newValue) {
	this->value = newValue;
}

void Account::deposit(int value) {
	this->value+= value;
}

bool Account::withdraw(int value) {
	if (value > this->value) {
		return false;
	} else {
		this->value -= value;
		return true;
	}
}

void Account::addloan(int value) {
	this->loan += value;
}

void Account::offloan(int value) {
	if (value > this->loan) {
		std::cout << "loan is less than money that you gave (your loan: " << this->loan << ")" << std::endl;
		return ;
	}
	this->loan -= value;
}

std::ostream& operator << (std::ostream& p_os, const Account& p_account)
{
	p_os << "[" << p_account.getId() << "] - [" << p_account.getValue() << "]";
	return (p_os);
}