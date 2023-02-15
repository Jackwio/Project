#include <iostream>
#include "Bank.h"
#include "Client.h"
using namespace std;

Bank::Bank(string name, string account, string password) {
	setName(name);
	setAccount(account);
	setPassword(password);
};

Bank::Bank() {
	name = "0000";
	account = "111111";
	password = "2222222";
}

void Bank::setAccount(string account) {
	this->account = account;
};
string Bank::getAccount() const {
	return account;
};

void Bank::setPassword(string password) {
	this->password = password;
};
string Bank::getPassword() const {
	return password;
};

void Bank::setName(string name) {
	this->name = name;
};
string Bank::getName() const {
	return name;
};