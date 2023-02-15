#include "Client.h"
#include "Administrator.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Bank.h"
#include "Client.h"
using namespace std;

Client::Client(string name, string account, string password, double totalMoney) : Bank(name, account, password) {
	setTotalMoney(totalMoney);
}

Client::Client() : Bank() {
	totalMoney = 0.0;
}

void Client::setTotalMoney(double totalMoney) {
	this->totalMoney = totalMoney;
}

double Client::getTotalMoney() const {
	return totalMoney;
}

bool TestIfMatch(Client& client) {
	
	string n,a,p;
	double t = 0.0;

	while (client.getName().size() < 5) {
		string n;
		cout << "Input the length > 5 name => ";
		cin >> n;
		if (n.size() > 5) {
			client.setName(n);
		}
	}
	

	while (client.getAccount().size() < 5) {
		cout << "Input the length > 5 account => ";
		cin >> a;
		if (a.size() > 5) {
			client.setAccount(a);
		}
	}
	

	while (client.getPassword().size() < 5) {
		cout << "Input the length > 5 password => ";
		cin >> p;
		if (p.size() > 5) {
			client.setPassword(p);
		}
	}
	

	while (client.getTotalMoney() < 0) {
		cout << "Input the > 0 deposit => ";
		cin >> t;
		if (t > 0) {
			client.setTotalMoney(t);
		}
	}

	return true;
}

void Client::mainMenu() {

	int operation;
	cout << "input opearation => ";
	cin >> operation;

	switch (operation)
	{
	case 1 :
		deposit();
		break;
	case 2 :
		withdraw();
		break;
	case 3 :
		fundTransfer();
		break;
	case 4 :
		record();
		break;
	}
	mainMenu();
}

bool Client::ifExist(string account) {
	
	string a, b, c;
	double d,s;
	fstream in;
	fstream out;

	in.open("Client.txt", ios::in);
	out.open("temp.txt", ios::out | ios::app);

	while (!in.eof()) {
		in >> a >> b >> c >> d;
		if (!in.fail()) {
			if (b == account) {
				cout << "Exist,money you want to transfer";
				cin >> s;

				out << a << " " << b <<
					" " << c << " " << d + s << endl;
			}
			else {
				out << a << " " << b <<
					" " << c << " " << d << endl;
			}
		}
	}
	out.close();
	in.close();
	return true;
}

void Client::deposit() {
	int moneyIn ;
	cout << "Input => " ;
	cin >> moneyIn ;
	if (moneyIn < 0 ) {
		cout << "Please Input valid money!!!" << endl ;
		mainMenu() ;
	}
	setTotalMoney(getTotalMoney() + moneyIn) ;
}

void Client::withdraw() {
	int moneyOut ;
	cout << "Input => " ;
	cin >> moneyOut ;
	if (moneyOut > getTotalMoney()) {
		cout << "Your moeny is not enough!!!" << endl ;
		mainMenu();
	}
	setTotalMoney(getTotalMoney() - moneyOut) ;
}

void Client::fundTransfer() {

	string a;
	cin >> a; 
	ifExist(a);
}

void Client::record() {
	cout << getTotalMoney() << endl ;
}