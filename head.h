#ifndef head_h
#define head_h
#include<string>
#include<map>

using namespace std;

string sign();
void terminateORnot();

class info{
public:

  void sortRecord();
  void addRecord();
  void checkRecord();
  void editRecord();
  void deleteRecord();
  void updateAccount();
  void displayAccount();
  void set(string username) {user = username;}

private:
  string user;
  map <int, string> expense = {{1,"Breakfast"},{2,"Dinner"},{3,"Snacks"},{4,"Grocery"},{5,"Social"},
                               {6,"Lunch"},{7,"Beverages"},{8,"Traffic"},{9,"Fun"},{10,"Clothing"},
                               {11,"Shopping"},{12,"Gifts"},{13,"Medical"},{14,"Investment"},{15,"Transfer"},
                               {16,"Rent"},{17,"Cash_Gift"},{18,"Mobile_Bill"},{19,"Visa"},{20,"Other"}};
  map <int, string> income = {{1,"Salary"},{2,"Bonus"},{3,"Allowance"},{4,"Investment"},{5,"Other"}};
  map <int, string> account = {{1,"Cash"}, {2,"Debit_Card"}, {3,"Credit_Card"}};
};

#endif
