#include <iostream>
#include "Source.h"
using namespace std;

int main(void) {

	string op;
	cin >> op;
	if (op.compare("Reg") == 0) {
		Register();
	}
	return 0;
}