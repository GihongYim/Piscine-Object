#include "Account.hpp"


Account::Account(int id) : id(id), value(0)
{

}

const int Account::getId() {
	return this->id;
}

int Account::getValue() {
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

std::ostream& operator << (std::ostream& p_os, const Account& p_account)
{
	p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
	return (p_os);
}