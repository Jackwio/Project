#include <iostream>
#include "Source.h"
using namespace std;

void LogIn();

int main(void) {

	int op;
	cout << "1.register\t2.login" << endl;
	cout << "Input = > ";
	cin >> op;
	if (op == 1) {
		Register();
	}
	else {
		LogIn();
	}
	return 0;
}