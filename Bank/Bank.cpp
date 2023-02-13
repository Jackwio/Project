#include <iostream>
#include <Login.h>
using namespace std;

int main() {

	string operation,name,account,password,deposit;
	
	do {

		if (operation.compare("reg") == 0) {
			cout << "Please Input Your name => ";
			cin >> name;
			cout << "Please Input Your account => ";
			cin >> account;
			cout << "Please Input Your password => ";
			cin >> password;
			cout << "Please Input Your deposit => ";
			cin >> deposit;

			Register register(name, account, password, deposit);
		}

	} while (true);

	return 0;
}