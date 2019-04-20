#ifndef head_h
#define head_h
#include<string>
using namespace std;

class Data{
public:
  void retrieve(string keyword);
  double sum(){return total};
  int  TypetoIndex(string type){return index;};

private:
  string user;
  string type,keyword;
  int index,total;
};

#endif
