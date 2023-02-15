#include <string>
using namespace std;
#ifndef    DR_R_R
#define    DR_R_R
class Bank {
private:
	string account;
	string password;
	string name;
public:
	Bank(string name, string account,
		string password);
	Bank();

	void setAccount(string account);
	string getAccount() const;

	void setPassword(string password);
	string getPassword() const;

	void setName(string name);
	string getName() const;
};
#endif