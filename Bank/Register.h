#include <iostream>
#include <string>
using namespace std;

class Register {
private:
	string name; 
	string account;
	string password;
	double totalMoney;
public:
	Register(string name, string account,
		string password, double totalMoney);

	void setName(string name);
	string getName() const;

	void setAccount(string account);
	string getAccount() const;

	void setPassword(string password);
	string getPassword() const;

	void setTotalMoney(string totalMoney);
	double getTotalMoney() const;

	//取得所有資訊
	void getInformation();
};

Register::Register(string name, string account,
	string password, double totalMoney) {
	setName();
	setAccount();
	setPassword();
	setTotalMoney();
}

void Register::setName(string name) {
	
	if (name.size() < 3 || name.size() > 10) {
		name.assign("Experience User");
		return;
	}
	this->name = name;
}

string Register::getName() const {
	return name;
}

void Register::setAccount(string account) {

	while(account.size() < 5) {
		cout << "Please input rightt account "
		cin >> account;
	}
	this->account = account;
}

string Register::getAccount() const {
	return account;
}

void LogRegisterin::setPassword(string password) {

	while (password.size() < 5) {
		cout << "Please input rightt password "
		cin >> password;
	}
	this->password = password;
}

string Register::getPassword() const {
	return password;
}

void Register::setTotalMoney(string totalMoney) {
	this->totalMoney = totalMoney;
}

string Register::getTotalMoney() const {
	return totalMoney;
}

void Register::getInformation() const {
	cout << "Your name is " << name << endl
		<< "Your account is " << account << endl
		<< "Your password is " << password << endl
		<< "Your totalMoney is " << totalMoney << endl;
}
