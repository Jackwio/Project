#include "Client.h"
#include "Administrator.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Bank.h"
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

	system("cls");
	int operation;
	cout << "1.deposit\t2.withdraw\t3.fundTransfer\t4.record" << endl ;
	cout << "input opearation => ";
	cin >> operation;

	switch (operation)
	{
	case 1 :
		system("cls");
		deposit();
		break;
	case 2 :
		system("cls");
		withdraw();
		break;
	case 3 :
		system("cls");
		fundTransfer();
		break;
	case 4 :
		system("cls");
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
	out.open("tem.txt", ios::out | ios::app);

	while (!in.eof()) {
		in >> a >> b >> c >> d;
		if (!in.fail()) {
			if (b == account) {
				//找該帳號物件??
				cout << "Exist,money you want to transfer";
				cin >> s;
				out << a << " " << b <<
					" " << c << " " << d + s << endl;
			}
			else if (b == getAccount()) {
				setTotalMoney(getTotalMoney() - s);
				out << a << " " << b <<
					" " << c << " " << getTotalMoney() << endl;
			}
			else {
				out << a << " " << b <<
					" " << c << " " << d << endl;
			}
		}
	}

	out.close();
	in.close();
	remove("Client.txt");
	rename("tem.txt", "Client.txt");
	
	return true;
}

void Client::deposit() {
	int moneyIn ;
	fstream out;
	fstream in;
	string a, b, c;
	double d;

	in.open("Client.txt", ios::in);
	out.open("tem.txt", ios::out | ios::out);
	cout << "Input => " ;
	cin >> moneyIn ;
	if (moneyIn < 0 ) {
		cout << "Please Input valid money!!!" << endl ;
		mainMenu() ;
	}
	while (!in.eof()) {
		in >> a >> b >> c >> d;
		if (!in.fail()) {
			if (b == getAccount()) {
				setTotalMoney(getTotalMoney() + moneyIn);
				out << a << " " << b << " " <<
					c << " " << getTotalMoney() << endl ;
			}
			else {
				out << a << " " << b << " " <<
					c << " " << d << endl;
			}
		}
	}
	
	out.close();
	in.close();

	//一定要先關檔案才能remove，否則會remove失敗
	remove("Client.txt");
	rename("tem.txt", "Client.txt");
	
}

void Client::withdraw() {
	int moneyOut ;
	string a, b, c;
	double d;
	fstream out;
	fstream in;
	out.open("tem.txt", ios::app | ios::out);
	in.open("Client.txt", ios::in);
	cout << "Input => " ;
	cin >> moneyOut ;
	if (moneyOut > getTotalMoney()) {
		cout << "Your moeny is not enough!!!" << endl ;
		mainMenu();
	}
	while (!in.eof()) {
		in >> a >> b >> c >> d;
		if (!in.fail()) {
			if (b == getAccount()) {
				setTotalMoney(getTotalMoney() - moneyOut);
				out << a << " " << b << " "
					<< c << " " << getTotalMoney() << endl ;
			} 
			else {
				out << a << " " << b << " "
					<< c << " " << d << endl ;
			}
		}
	}

	in.close();
	out.close();

	remove("Client.txt");
	rename("tem.txt", "Client.txt");
	
}

void Client::fundTransfer() {

	string a;
	cout << "Input the account you want to transfer = > ";
	cin >> a; 
	ifExist(a);
}

void Client::record() {
	cout << getTotalMoney() << endl ;
}