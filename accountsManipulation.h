#ifndef head_h
#define head_h
#include<string>
using namespace std;

class account{
public:
	void UpdateAccount(char PosONeg,int amount, int type, string useracount);
	void DisplayAccount(string user);


private:
 	string user;
};

#endif