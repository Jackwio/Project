#include "Bank.h"
class Client;
#ifndef    DC_C_C
#define    DC_C_C
class Administrator : public Bank {
	friend bool TestIfMatch(Client client);
public:

};
#endif