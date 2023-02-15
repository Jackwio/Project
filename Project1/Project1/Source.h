#include <iostream>
#include <fstream>
using namespace std;
#include "Client.h"
#include <vector>

vector<Client> clientObj;
Client currentClient;

void LogIn() {
	string names, accounts, passwords;
	ifstream in;
	double deposits;

	cout << "Please Input Your account => ";
	cin >> accounts;
	cout << "Please Input Your password => ";
	cin >> passwords;
	/*for (auto it = clientObj.begin(); it != clientObj.end(); it++) {
		if (it->getAccount().compare(accounts) == 0) {
			currentClient = *it;
			break;
		}
	}*/
	in.open("Client.txt", ios::in);
	while (!in.eof()) {
		in >> names >> accounts >> passwords >> deposits;
	}
	in.close();
	currentClient.mainMenu();
}

void Register() {

	string names, accounts, passwords;
	double deposits;
	ofstream out;
	cout << "Please Input Your name => ";
	cin >> names;
	cout << "Please Input Your account => ";
	cin >> accounts;
	cout << "Please Input Your password => ";
	cin >> passwords;
	cout << "Please Input Your deposit => ";
	cin >> deposits;

	Client clients(names, accounts, passwords, deposits);
	bool Matches = TestIfMatch(clients);

	//用 | 讓兩個同時使用
	out.open("Client.txt", ios::out | ios::app );

	out << names << " " << accounts << " "
		<< passwords << " " << deposits << endl;
	out.close();
	
	if (Matches) {
		clientObj.push_back(clients);
		cout << "Register successfully" << endl ;
		
		LogIn();
	}
	else {
		cout << "Fail";
	}
	
}

