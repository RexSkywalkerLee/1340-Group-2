#ifndef head_h
#define head_h
#include<string>
using namespace std;

class Records{
public:
  void sign();
  void add();
  void check();
  string username();

private:
  string user;
};

#endif
