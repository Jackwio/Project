#include <string>
#include "Bank.h"
using namespace std;
#ifndef    DS_S_S
#define    DS_S_S
class Client : public Bank {
	friend bool TestIfMatch(Client& client);
private:
	double totalMoney;
public:
	Client(string name, string password,
		string account, double totalMoney);
	Client();
	void setTotalMoney(double totalMoney);
	double getTotalMoney() const;
	void mainMenu();
	//void LogOut();
	bool ifExist(string account);
	void deposit();
	void withdraw();
	void fundTransfer();
	void record();
};
#endif